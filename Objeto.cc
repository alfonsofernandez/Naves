#include "Objeto.h"

Objeto::Objeto(){       
	this->currentFrame=0;
	this->speed=80;                                  
	gettimeofday(&	this->timeIni, NULL);    
  	
}
Objeto::Objeto(string fich){       
		this->currentFrame=0;
		this->speed	=80;                                  
		gettimeofday(&	this->timeIni, NULL);          
		this->loadSprite(fich,currentFrame);
}

void Objeto::loadSprite(string fichName,int frame){
	ifstream fichero;                                       
	string cadena;
		
	fichero.open(fichName.c_str(),ios::in);
	getline(fichero,cadena);
	int cont=0;      	
  while(!fichero.eof()) { 
		this->lines[cont]=cadena; 
		getline(fichero,cadena);    
		cont++;
 	}     
	fichero.close(); // cerrar el fichero else     
	
}


