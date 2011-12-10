#include "Disparos.h"

Disparos::Disparos(){
	for(int i=0;i<100;i++){
		this->lista[i].x=0;
		this->lista[i].y=0;
		this->lista[i].activo=false;		
	}                             
	this->numDisparos=0;
}                         


void Disparos::update(){
	for(int i=0;i<100;i++){
	 	if(this->lista[i].activo){
			
			this->lista[i].x++;			
			
						
		}
	}

}  

void Disparos::print(){
	for(int i=0;i<100;i++){
	 	if(this->lista[i].activo) mvaddstr(this->lista[i].y,this->lista[i].x,"*");
	}	
}
void Disparos::switchOn(){	             
}


void Disparos::switchOff(){
 
}

void Disparos::nuevo(int px, int py){
	
	if(this->numDisparos<100){		
		this->lista[numDisparos].x= px;
		this->lista[numDisparos].y= py;
		this->lista[numDisparos].activo=true;				
		this->numDisparos++;		
	}
	
}

                          

