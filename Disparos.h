#include "StdPijo.h"
#include <fstream>      
// Incluimos cabeceras para números aleatorios y retardos
#include <ctime>
#include <cstdlib>
#include <unistd.h>  
#include <string>
#include <sstream>
#include "sys/time.h"

typedef struct {
	
	int x, y;
	bool activo;
	
} Disparo;
             
typedef Disparo listDisparos[100];

class Disparos{
 
	public:  
		Disparos(); //Constructor vacio;    		 		
		int numDisparos;
		listDisparos lista;
		 				
		void  update();
		void  switchOn();
		void  switchOff();
		void	nuevo(int x, int y);			//Crea un disparo 
		
		void print();
		
		private:			
};