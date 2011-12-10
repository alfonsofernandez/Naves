#include "Pantalla.h"                                   
#include "ncurses.h"

Pantalla::Pantalla(  ){

 StdPijo &	pijo = StdPijo::p(); 
	pijo.init();
	pijo.clearScreen();
	pijo.setGlobalEscapeDelay(0);
	pijo.setColor(ABOLD, CYELLOW, CBLACK);	        
	contLogo=0;     
 

}

void Pantalla::mostrarLogo(timeval &t1){
	
 	timeval t2;                                     //difrencial del tiempo
	double elapsedTime;                             //Tiempo transcurrido
	stringstream ss;                                //Conversión entero cadena
	int numItems = sizeof(linesLogo) / sizeof(string);	//numero de items en el array	
	string cadena;                              
	//Cargando fichero de texto que contiene el logo
	gettimeofday(&t2, NULL);                      
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms 
	
  ss <<  elapsedTime;                   
	cadena = ss.str(); 
	
	if(elapsedTime>80){                                 //Cada 60 milisegundos
		
		for(int y=0; y <24 ; y ++){       
			if(y+contLogo<73){ 
				mvaddstr(y,0,linesLogo[y+contLogo].c_str());
				gettimeofday(&t1, NULL);						                      
			}else{
			 break;
			}
		}		 
		           
		 if(contLogo<53){ contLogo++;}
	}
	
 	refresh();
	  
  
} 
 
                            

void Pantalla::moverObjeto(string lines[],timeval & t1,int &iniPantalla){
			timeval t2;                                      
			double elapsedTime;
			string	cadena;
			int numItems = sizeof(lines) / sizeof(string);
			gettimeofday(&t2, NULL); 	 
			elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
			elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms         

			//Si han pasado 40 segundos... 
			if(elapsedTime>=35) {			 
			iniPantalla++;
			gettimeofday(&t1, NULL); 
			elapsedTime=0;         	 
			for(int j=0;j<24;j++){    									    
				if(iniPantalla< lines[j].length()) 
						if( lines[j].length()>80)
							cadena = lines[j].substr(iniPantalla,80); 								       
						else
							cadena = lines[j].substr(iniPantalla,lines[j].length() ); 								       

					mvaddstr(j,0,cadena.c_str());
			}
		}
}

/* Lee de fichero a array de strings
 *
 */
void Pantalla::fromFile(string nomFich, LinPantalla &lines,Par xy){  //pasar un fichero a una 
	ifstream fichero;                               //Gestionar fichero
	string cadena;                                  //Cadena para mostrar por pantalla	
	int x,y;
	x=xy[0];
	y=xy[1];              
	
	fichero.open(nomFich.c_str(),ios::in);               //Abrir fichero         
	
	                     //Leer primera linea    
	
 	for(int j=0;j<50+y;j++){ 	
		getline(fichero,cadena); 
	  lines[j] = cadena; 								       	       		
  }


 }                   

void Pantalla::printDisparo(int x, int y){
	     
		mvaddstr(y,x," -");
    
}

void Pantalla::mover(string lines[],timeval & t0,int & iniPantalla2,int iniY,int speed){
			timeval t3;               
			string	cadena;                   
			double el2;

			int numItems = (sizeof(lines) / sizeof(string));

      mvaddstr(0,0,lines[0].c_str());


			sleep(2);
               /*
			gettimeofday(&t3, NULL);  		 
			el2 = (t3.tv_sec - t0.tv_sec) * 1000.0;      // sec to ms
			el2 += (t3.tv_usec - t0.tv_usec) / 1000.0;   // us to ms

            					
			if(el2>=speed) {			 
			iniPantalla2++;
			gettimeofday(&t0, NULL); 
			el2=0;      

	 
			}                     
			 		for(int j=0;j<=numItems;j++){    									    
					mvaddstr(iniY+j,iniPantalla2,lines[j].c_str());
			}
          */                                                                       
}       
                                      

   

	 /* 				         
						 //  pijo.setColor(ANORMAL, CWHITE, CCYAN);           
 						move(10,5); 	
						printw("elapsedTime   posX:%d",iniPantalla); 
 						mvaddstr( 9,65,  "  ________   ");
						mvaddstr(10,65, "/          \\");
						mvaddstr(11,65, "|   ^   ^   |");
						mvaddstr(12,65, "|     O     |");
						mvaddstr(13,65, "\\         /  ");
						mvaddstr(14,65, "/ /\\  /\\  \\  ");
						mvaddstr(15,65, "| |  | | | | ");
						mvaddstr(16,65, "\\/  \\ /  \\/  ");



	*/                               



      

void Pantalla::printNave(int x, int y){
	                      
				
				mvaddstr( y,x, "/|__ ");
				mvaddstr( y+1,x, "----/");
			
}




  
  