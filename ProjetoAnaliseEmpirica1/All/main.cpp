#include <iostream>
#include <chrono>
#include <iomanip>

#include "search.h"

#define N_AVERAGE 100
#define PRECISION 4

typedef int (*SearchFunction)(long int *, long int*, long int);

int main(){

	//array de funções
	SearchFunction functions[] = {edb::linearSearch,
								  edb::iteBinarySearch,
								  edb::recBinarySearch,
								  edb::iteTernarySearch,
								  edb::recTernarySearch,
								  edb::jumpSearch,
								  edb::fibSearch};

	int s, 		   //aux para calcular tamanho
		n_samples, //quantidade de amostras
		s_samples; //tamanho das amostras
	long int *v;
	long int value = s_samples*n_samples;

	//ler quantidade e tamanho das amostras
	std::cin >> n_samples >> s_samples;

	//aloca o array
	v = new long int[n_samples * s_samples];

	//inicia o vetor com valores ordenados
	for (int i = 0; i < n_samples * s_samples; i++)
		v[i] = i;
	
	//para cada amostra
	for (int i = 1; i <= n_samples; i++){
		s = i * s_samples;

		//imprime o tamanho da amostra
		std::cout << s << ", ";

		//simula o pior caso para cada função
		//ou seja, o valor não é encontrado
		for (auto & e : functions){
			double time = 0;

			//executa a função N_AVERAGE vezes e em seguida 
			//calcula a média de tempo das execuções
			for (int i = 0; i < N_AVERAGE; i++){
				//inicia o cronometro
				auto start = std::chrono::steady_clock::now();

				//executa as funções
				int x = e(v, v + s, value);

				//finaliza o cronometro
				auto end = std::chrono::steady_clock::now();

				//calcula tempo decorrido em nano segundos
				time += (std::chrono::duration <double, std::nano> (end-start).count()) / N_AVERAGE;
			}

			//imprime uma linha com os tempos das funções
			std::cout << time << std::scientific << std::setprecision(PRECISION)<<", ";
		}
		
		//pula linha
		std::cout << "END" << std::endl;
	}

	return 0;
}