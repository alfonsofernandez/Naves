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


class Objeto{
                                     
public:
		Objeto(); //consturctor  
		Objeto(string); //consturctor desde fichero
		
    timeval timeIni,timeInterval;
		int speed;
		int currentFrame;	 
		int posX;
		int posY; 
		string lines[];
		
		void loadSprite(string fichName,int frame);
	  
};