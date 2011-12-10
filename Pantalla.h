#include "StdPijo.h"
#include <fstream>      
// Incluimos cabeceras para números aleatorios y retardos
#include <ctime>
#include <cstdlib>
#include <unistd.h>  
#include <string>
#include <sstream>
#include "sys/time.h"

using namespace STDP;             

typedef string LinPantalla[50]; // un array que representa las 24 lineas de la pantalla en strings.       

typedef int  Par[2]; //para definir cordendas [0] es x    [1] es y

class Pantalla{
	
	public:
		Pantalla(); //Constructor
		void mostrarLogo(timeval &t1); //Funcion que muestra por pantalla el logo 
		void moverObjeto(string lines[],timeval & t1,int &iniPantalla);
		void mover(string lines[],timeval & t0,int & iniPantalla2,int iniY,int speed);		
		void fromFile(string nomFich, LinPantalla &lines,Par); 
		void printNave(int x, int y);
		
		void printDisparo(int , int);
				
 	  string  linesStars[24];
		int		iniPantalla2;

	
   private:                
		//Para el logotipo
		int contLogo;          		
		string linesLogo[73];                               //Array lineas del fichero del logo   
		
		
		//Para las estrellas 
		
		
	
	} ;                               
	

