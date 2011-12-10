/**
 *   Copyright 2011 (c) Francisco José Gallego Durán <fgallego@byterealms.com>
 *   Copyright 2011 (c) ByteRealms <info@byterealms.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 3 of the License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 */

//////////////////////////////////////////////////
// Ejemplo de uso de la versión básica de StdPijo
//////////////////////////////////////////////////

// Incluimos la cabecera principal de StdPijo
#include "StdPijo.h"
#include <fstream>      // Incluimos cabeceras para números aleatorios y retardos
#include <ctime>
#include <cstdlib>
#include <unistd.h>  
#include <string>
#include <sstream>
#include "sys/time.h"         
#include "Objeto.h" 
#include "Pantalla.h"
#include "Disparos.h"
                                     
// Usamos globalmente el espacio de nombres de stdpijo (STDP)
using namespace STDP;             

bool checkTime(timeval &t1,int fps);   

bool checkTime(timeval &t1,int fps){     
	bool r=false;
	double elapsedTime;
	timeval t2;
	gettimeofday(&t2, NULL);                      		
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms 
  
  r= (elapsedTime>fps);
	
	if(r) gettimeofday(&t1, NULL);                      		
	return r;
}

int
main (void)
{                           
               
	Disparos shot;
	char tecla;   
	Pantalla p;  
 
 LinPantalla lines;
	Par xy;                                 
	timeval t0,t1; 
	int posx=0;
	int posy=0;
 	
 	gettimeofday(&t0, NULL);		          
	gettimeofday(&t1, NULL);		
	double elapsedTime;
		
	int contador=80;	  //incremento de x de la nave secundaria
		
	int contDisparos = 0;//Cuenta cuantos disparos realizados
	xy[0]=0;
	xy[1]=0;  
	
	 p.fromFile("stars.txt",lines,xy);
	
	         
	             
while(true){
 //	erase();
		if(checkTime(t0,80)){  //plano scrooll lento    
		//	 erase();			
			  if(contador<350) contador++;			  						
		}                              
	  
	 if(checkTime(t1,80)){
					
				tecla = getch();
				switch(tecla){				
						case  97: if(posx>0)	  posx--; break;   
					  case 100: if(posx<80)   posx++; break;   					             
				 		case 115: if(posy<24)	  posy++; break;
				 		case 119: if(posy>0)	  posy--; break;
				    
				    case  32:
						case  13:  //Cuando pulsa el botón de disparo .. 	    
							shot.nuevo(posx+4,posy+1);
							 						
					  break;						      						
					}
			
				shot.update(); 
			}     
				
				
				for(int c=0;c<24;c++)	 mvaddstr(c,0,lines[c+posy].substr(contador,80).c_str());			  
		    p.printNave(posx,posy);
			//	p.printEnemi(posx,posy);  
				
				shot.print();
			  
		 		    
				
				refresh(); 
				//sleep(1);			
  }   //en while         	
  
}  //end main     

                 
      


/*


	ejemplo elapsed time 
	
	
		 	gettimeofday(&t2, NULL);
		 	gettimeofday(&t3, NULL);

			    // compute and print the elapsed time in millisec
			    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
			    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms 
					el2 = (t3.tv_sec - t0.tv_sec) * 1000.0;      // sec to ms
					el2 += (t3.tv_usec - t0.tv_usec) / 1000.0;   // us to ms

                
					if(elapsedTime>=80) {
				 // 	stdp.clearScreen();
						move(1,p1x); 		
					 	printw(" ");					 
						p1x++;
		 		
						gettimeofday(&t1, NULL); 
						elapsedTime=0; sec++;       
	 
					} 
					move(1,p1x);  
					printw("."); 
	
					if(el2>=60)
					{  
						//stdp.clearScreen();   
						move(3,p2x);  
						printw(" ");  						
						p2x++;
 						gettimeofday(&t0, NULL); 
						el2=0;
					}             
	
					move(3,p2x);  					       
					printw(",");  						
	
					 //move(10,5); 	
					//printw("elapsedTime  %d:%f posX:%d",sec,elapsedTime,p1x);
	*/

