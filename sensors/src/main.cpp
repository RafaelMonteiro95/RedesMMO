#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "TempSensor.hpp"
#include "PlugSensor.hpp"
#include "LockSensor.hpp"
#include "LocationSensor.hpp"

int main(int argc, char *argv[]){
	LocationSensor *locs;
	TempSensor *ts;
	PlugSensor *ps;
	LockSensor *ls;

	// Parâmetros dos sensores recebidos via argumento na execução
	if (argc != 2){
		printf("Erro\n");
	}
	else{
		if (strlen(argv[1]) != 2){
			printf("Erro\n");
		}
		else{
			switch (argv[1][0]){
				case '1':
					ls = new LockSensor(atoi(argv[1]), "127.0.0.1", 8888);
					ls->start();

					break;
				case '2':
					locs = new LocationSensor(atoi(argv[1]), "127.0.0.1", 8888);
					locs->start();

					break;
				case '3':
					ps = new PlugSensor(atoi(argv[1]), "127.0.0.1", 8888);
					ps->start();

					break;
				case '4':
					ts = new TempSensor(atoi(argv[1]), "127.0.0.1", 8888);
					ts->start();

					break;
				default:
					break;
			}
		}
	}

	return 0;
}