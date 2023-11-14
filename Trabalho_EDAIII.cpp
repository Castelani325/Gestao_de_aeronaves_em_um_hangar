// Trabalho EDA III
// Otavio Castelani

//Tema : Controle de aeronaves em um hangar

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include "PLACON.h"



int main()
	{
//	int numero_ale = numero_aleatorio();
//	std::cout <<numero_ale;
	int opcao;
	do
		{
		menu();

		std::cin >> opcao;
		switch (opcao)
				{
        		case 1:
        			std::cout << "\nVoce escolheu a opcao INICIAR UM BANCO DE REGISTROS DE AERONAVES." << std::endl;
					Registra_Anv_Novo_Banco();
					break;


        		case 2:
            		std::cout << "\nVoce escolheu a opcao INSERIR NOVA AERONAVE." << std::endl;
            	   	Novo_Registro();
					break;

           		case 3:
            		std::cout << "\nVoce escolheu a opcao REMOVER AERONAVE." << std::endl;
            		std::cout << "Escolha o ID da aeronave que deseja remover." << std::endl;

					int chave;
            		std::cin >> chave;
            		Remover_Registro(chave,"Banco_de_Registros.txt");
            		//Encontrar_E_Remover_Registro(chave,"Banco_de_Registros.txt");
					break;

				case 4:
           		 	std::cout << "\nVoce escolheu a opcao MODIFICAR DADOS DE UMA AERONAVE." << std::endl;
           		 	std::cout << "Escolha o ID da aeronave que deseja EDITAR." << std::endl;
					int chave4;
            		std::cin >> chave4;
					Editar_Campo_Registro(chave4,"Banco_de_Registros.txt");
					break;


        		case 5:
            		std::cout << "\nVoce escolheu a opcao BUSCAR DADOS DE UMA AERONAVE." << std::endl;
            		std::cout << "Escolha o ID da aeronave que deseja ENCONTRAR." << std::endl;
					int chave2;
            		std::cin >> chave2;
					Encontrar_E_Imprimir_Registro(chave2,"Banco_de_Registros.txt");
					break;


        		case 6:
           		 	std::cout << "\nVoce escolheu a opcao IMPRIMIR RELATORIO DE AERONAVES.\n\n" << std::endl;
           		 	Imprime_Relatorio("Banco_de_Registros.txt");
					break;
					
					
        		case 7:
        			std::cout << "\nVoce escolheu a opcao EDITAR HORAS DE VOO DE AERONAVE." << std::endl;
            		std::cout << "Escolha o ID da aeronave que deseja MODIFICAR AS HORAS." << std::endl;
					int chave5;
            		std::cin >> chave5;
					Edita_horas(chave5,"Banco_de_Registros.txt");
					break;
					
					
            	case 8:
            		std::cout << "\nVoce escolheu a opcao GERAR REGISTROS ALEATORIOS(SEMINARIO).\n\n" << std::endl;
            		std::cout << " Quantos Registros quer criar ?" ;
            		int aleatorio;
            		std::cin >> aleatorio;
            		registros_aleatorios(aleatorio,"Banco_de_Registros.txt");
					break;
					
				case 9:
            		std::cout << "\nVoce escolheu a opcao SAIR DO PROGRAMA." << std::endl;
            		std::cout << " Ate Logo ! " ;
					break;
					
								 		
        		default:
            		std::cout << "\nOpcao invalida. \n\n" << std::endl;
            		break;
    			}
    	} while (opcao>=1 && opcao<=8);
    return 0;

	}
