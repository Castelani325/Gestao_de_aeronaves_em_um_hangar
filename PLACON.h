//Biblioteca de funcoes e Structs
//Otavio Castelani

#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <random>
#include <ctime>


//OK //Funcao ASCII Art
void aviao()
		{
		std::cout << "                              |\n";
    	std::cout << "                               |\n";
    	std::cout << "                               |\n";
    	std::cout << "                             .-'-.\n";
    	std::cout << "                            ' ___ '\n";
    	std::cout << "                  ---------'  .-.  '---------\n";
    	std::cout << "  _________________________'  '-'  '_________________________\n";
    //	std::cout << "   ''''''-|---|--/    \==][^',_m_,'^][==/    \--|---|-''''''\n";
    //	std::cout << "                 \    /  ||/   H   \||  \    /\n";
    //	std::cout << "                  '--'   OO   O|O   OO   '--'  \n\n\n\n";

		}
//OK
void menu()
	{
		
	std::cout << " Seja Bem Vindo(a) ao SISTEMA DE PLANEJAMENTO E CONTROLE DE AERONAVES DO AEROPORTO FUCAPI \n Do que Precisa ?\n\n " ;

	aviao();

	std::cout << "  1- INICIAR UM BANCO DE REGISTROS DE AERONAVES.\n " ;
	std::cout << " 2- INSERIR NOVA AERONAVE.\n " ;
	std::cout << " 3- REMOVER AERONAVE.\n " ;
	std::cout << " 4- MODIFICAR DADOS DE UMA AERONAVE.\n " ;
	std::cout << " 5- BUSCAR DADOS DE UMA AERONAVE.\n " ;
	std::cout << " 6- IMPRIMIR RELATORIO DE AERONAVES.\n " ;
	std::cout << " 7- EDITAR HORAS DE VOO DE AERONAVE.\n " ;
	std::cout << " 8- GERAR REGISTROS ALEATORIOS(SEMINARIO).\n " ;
	std::cout << " 9- SAIR DO PROGRAMA.\n " ;
	std::cout << "____________________________________________________________\n";

	}
	

//OK
struct Registro
	{
    int Id_aeronave;
    std::string Matricula_anv;
    std::string Modelo_anv;
    std::string Esquadrao_anv;
    int Ano_Fabricacao_anv;
    int Horas_de_voo;

    Registro() : Id_aeronave(0), Ano_Fabricacao_anv(0), Horas_de_voo(0) {};

    Registro(int id, const std::string& matricula, const std::string& modelo, const std::string& esquadrao, int ano, int horas)
        : Id_aeronave(id), Matricula_anv(matricula), Modelo_anv(modelo), Esquadrao_anv(esquadrao),Ano_Fabricacao_anv(ano),Horas_de_voo(horas)  {}
		
	};
	
//OK	
int Obter_Ultimo_Id(const char* nomeArquivo)
	{
    std::ifstream arquivoEntrada(nomeArquivo);

    int ultimoId = 0;
    std::string linha;

    while (std::getline(arquivoEntrada, linha))
    	{
        std::istringstream lin(linha);
        int id;
        std::string delimiter;

        // Extrai o c�digo de identifica��o da linha
        if (lin >> id >> delimiter)
        	{
            ultimoId = id;
        	}
    	}

    arquivoEntrada.close();

    return ultimoId;
	}
	
//OK
bool Se_Arquivo_Esta_Vazio(const std::string& NomeArquivo)
	{
    std::ifstream arquivo(NomeArquivo.c_str());
    return arquivo.peek() == std::ifstream::traits_type::eof();
	}
//OK
void Salva_Em_Arquivo(const std::string& NomeArquivo, int Id_aeronave, const std::string& Matricula_anv,
                      const std::string& Modelo_anv, const std::string& Esquadrao_anv, int Ano_Fabricacao_anv, int Horas_de_voo)
	{

    std::ofstream arquivo(NomeArquivo.c_str(), std::ios::app); //"std::ios::app" indica que os dados ser�o adicionados ao final do arquivo, semelhante ao append do Python

    if (arquivo.is_open())
    	{
        arquivo << Id_aeronave << " -- " << Matricula_anv << " -- " << Modelo_anv << " -- " << Esquadrao_anv << " -- " << Ano_Fabricacao_anv << " -- " << Horas_de_voo <<"\n";
        arquivo.close();
        std::cout << "Registro Salvo Com Sucesso.\n";
    	}
    else
    	{
        std::cerr << "Erro ao Abrir o arquivo. \n";
    	}
	}
//OK
int Registra_Anv_Novo_Banco()
	{
	 if (Se_Arquivo_Esta_Vazio("Banco_de_Registros.txt"))
    	{
        std::cout << "Nao ha arquivo em utilizacao ainda.\n";
    	}
    else
		{
		std::cout << "Ja existe um banco de dados em utilizacao.\n";
		return 0;
		}
	int id = 1;
	
	std::cout << "Codigo de Identificacao da aeronave: " << id << "\n";
				
	std::cout << "Qual seria o a MATRICULA da aeronave ?\n";
	std::string matricula;
	std::cin >> matricula;

    std::cout << "Qual seria o a MODELO da aeronave ?\n";
	std::string modelo;
	std::cin >> modelo;

    std::cout << "Qual seria o ESQUADRAO da aeronave ?\n";
	std::string esquadrao;
	std::cin >> esquadrao;

    std::cout << "Qual e o ANO DE FABRICACAO da aeronave ?\n";
	int ano;
	std::cin >> ano;
	
	std::cout << "Quantas HORAS essa aeronave ja voou () ?\n";
	int horas;
	std::cin >> horas; 

	Salva_Em_Arquivo("Banco_de_Registros.txt", id, matricula, modelo, esquadrao, ano, horas);
	}
	

//OK
int Novo_Registro()
	{
	 if (Se_Arquivo_Esta_Vazio("Banco_de_Registros.txt"))
    	{
        std::cout << "Nao ha arquivo em utilizacao ainda.\n O usuario precisa criar um novo Banco de dados . \n";
        return 0;
    	}
    else
		{
		std::cout << "Ha um Banco de dados em utilizacao./n Insira seu novo Registro.\n";
		}

	int ultimoId = Obter_Ultimo_Id("Banco_de_Registros.txt");
	int novoId = ultimoId+1;
	
	std::cout << "Codigo de Identificacao da aeronave: " << novoId << "\n";
				
				std::cout << "Qual seria o a MATRICULA da aeronave ?\n";
				std::string matricula;
				std::cin >> matricula;

            	std::cout << "Qual seria o a MODELO da aeronave ?\n";
				std::string modelo;
				std::cin >> modelo;

            	std::cout << "Qual seria o ESQUADRAO da aeronave ?\n";
				std::string esquadrao;
				std::cin >> esquadrao;

            	std::cout << "Qual e o ANO DE FABRICACAO da aeronave ?\n";
				int ano;
				std::cin >> ano;
				
				std::cout << "Quantas HORAS essa aeronave ja voou () ?\n";
				int horas;
				std::cin >> horas;

				Salva_Em_Arquivo("Banco_de_Registros.txt", novoId, matricula, modelo, esquadrao, ano, horas);
	}
//!!!Nao esta sendo usada!!!
/*int Verifica_se_vazio()
	{
	if (Se_Arquivo_Esta_Vazio("Banco_de_Registros.txt"))
    	{
    	std::cout << "O arquivo esta vazio.\n";
    	return 0;
    	}
    else
		{
		std::cout << "Ja existe um banco de dados em utilizacao.\n";
		std::cout << "Deseja retornar ao Menu(1) ou Finalizar(2) ?.\n";
		int opcao2;
		std::cin >> opcao2;
		if(opcao2==1)
			{
			return 1;
			}
		else
			{
			return 0;
			}
		}
	}*/
// OK
void Encontrar_E_Imprimir_Registro(int chaveProcurada, const std::string& nomeArquivo)
	{

    std::ifstream arquivoEntrada(nomeArquivo.c_str());
    std::string linha;// variavel

    bool chaveEncontrada = false; // variavel

     while (std::getline(arquivoEntrada, linha))
	 	{
    	std::istringstream lin(linha);
    	Registro regis;

    	std::string delimiter = " -- ";

    	if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv >> delimiter >> regis.Horas_de_voo)
			{

        	//std::cout << "Linha lida: " << linha << "\n";
        	std::cout << "\n Chave encontrada: " << regis.Id_aeronave << "\n";
			std::cout << "\n";

        	if (regis.Id_aeronave == chaveProcurada)
				{
            	chaveEncontrada = true;
            	std::cout << "Registro encontrado:\n";
            	std::cout << "Id_aeronave: " << regis.Id_aeronave << "\n";
            	std::cout << "Matricula_anv: " << regis.Matricula_anv << "\n";
            	std::cout << "Modelo_anv: " << regis.Modelo_anv << "\n";
            	std::cout << "Esquadrao_anv: " << regis.Esquadrao_anv << "\n";
            	std::cout << "Ano_Fabricacao_anv: " << regis.Ano_Fabricacao_anv << "\n";
            	std::cout << "horas voadas: " << regis.Horas_de_voo << "\n";
            	
            	std::cout << "\n\n\n";
				break;
        		}
    		}

		else
			{
            std::cerr << "Erro ao ler a linha: " << linha << "\n";
        	}
    	}
    arquivoEntrada.close();
    if (!chaveEncontrada)
		{
        std::cout << "Chave nao encontrada.\n";
    	}
	}
// OK
bool comparar_Por_Id(const Registro& a, const Registro& b) 
	{
    return a.Id_aeronave < b.Id_aeronave;
	}

void Imprime_Relatorio(const std::string& nomeArquivo)
	{
   	int Contador_Registro = 0;
    std::ifstream arquivoEntrada(nomeArquivo.c_str());
    std::string linha;// variavel

    std::vector<Registro> registros;  // Vetor para armazenar os registros
   
    while (std::getline(arquivoEntrada, linha))
	 	{
    	std::istringstream lin(linha);
    	Registro regis;

    	std::string delimiter = " -- ";

    	if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv >> delimiter >> regis.Horas_de_voo)
			{
            registros.push_back(regis);
            Contador_Registro++;
		   	}

		else
			{
            std::cerr << "Erro ao ler a linha: " << linha << "\n";
        	}
    	}
    std::sort(registros.begin(), registros.end(), comparar_Por_Id);
    
    std::cout << "ID Anv -- Matricula -- Modelo -- Esquadrao -- Ano Fabricacao -- H/Voadas\n";
    for (const auto& regis : registros)
		{
        std::cout << regis.Id_aeronave << " -- " << regis.Matricula_anv << " -- " << regis.Modelo_anv << " -- "
                  << regis.Esquadrao_anv << " -- " << regis.Ano_Fabricacao_anv << " -- " << regis.Horas_de_voo << "\n";
    	}
    std::cout << "Total de registros: " << Contador_Registro << "\n\n";
    arquivoEntrada.close();
    
    }

bool Verificar_Se_Chave_Existe(int chaveProcurada, const std::string& nomeArquivo) 
	{
    std::ifstream arquivoEntrada(nomeArquivo.c_str());
    std::string linha;
    while (std::getline(arquivoEntrada, linha)) 
		{
        std::istringstream lin(linha);
        Registro regis;
        std::string delimiter = " -- ";

        if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv) 
			{
            if (regis.Id_aeronave == chaveProcurada) 
				{
                return true; // Chave encontrada
            	}
        	}
    	}

    return false; // Chave n�o encontrada
	}

// OK 
void Remover_Registro(int chaveProcurada, const std::string& nomeArquivo)
	{
	bool chaveExiste = Verificar_Se_Chave_Existe(chaveProcurada, nomeArquivo);
	if (Se_Arquivo_Esta_Vazio("Banco_de_Registros.txt")==1)
		{
		std::cout << "Arquivo nao tem registros.\n\n";
		return;
		}
	else if(!chaveExiste)
		{
		std::cout << "Id nao encontrada.\n\n";
		return;
		}
	else
		{
	
		std::ifstream arquivoEntrada(nomeArquivo.c_str());
    	std::ofstream arquivoTemp("temp.txt");

    	std::string linha;
    	bool chaveEncontrada = false;

    	while (std::getline(arquivoEntrada, linha))
			{
        	std::istringstream lin(linha);
        	Registro regis;
        	std::string delimiter = " -- ";

        	if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv)
				{
           	 if (regis.Id_aeronave == chaveProcurada)
					{
            		std::cout << "Registro encontrado:\n";
            		std::cout << "Id_aeronave: " << regis.Id_aeronave << "\n";
            		std::cout << "Matricula_anv: " << regis.Matricula_anv << "\n";
            		std::cout << "Modelo_anv: " << regis.Modelo_anv << "\n";
            		std::cout << "Esquadrao_anv: " << regis.Esquadrao_anv << "\n";
            		std::cout << "Ano_Fabricacao_anv: " << regis.Ano_Fabricacao_anv << "\n";
            		std::cout << "Horas Voadas: " << regis.Horas_de_voo << "\n";
            		std::cout << "\n\n\n";
               		chaveEncontrada = true;
                                
            		}
				else
					{
             	  arquivoTemp << linha << "\n";
            		}
        		}
    		}
    	char opcao3;
    	std::cout << "Deseja remover este registro? (S/N): ";
    	std::cin >> opcao3;
    	if (opcao3 == 'S' || opcao3 == 's')
			{
    		arquivoEntrada.close();
    		arquivoTemp.close();
    	
       	 std::string Endereco_doc = "D:\\Trabalho_EDA_III\\Docs_Finais_Struct_#Finalizado\\Banco_de_Registros.txt";
    		std::string Remocao = "powershell Remove-Item -Path \"" + Endereco_doc + "\" -Force";
    		int removeResult = system(Remocao.c_str());
    
    		if (removeResult == 0) 
				{
       			//std::cout << "File removal successful." << std::endl;
           		std::string Endereco_Antigo = "D:\\Trabalho_EDA_III\\Docs_Finais_Struct_#Finalizado\\temp.txt";
        		std::string Endereco_Novo = "D:\\Trabalho_EDA_III\\Docs_Finais_Struct_#Finalizado\\Banco_de_Registros.txt";
        		std::string Renomear = "powershell Rename-Item -Path \"" + Endereco_Antigo + "\" -NewName \"" + Endereco_Novo + "\" -Force";
        		int renameResult = system(Renomear.c_str());
        		if (renameResult == 0) 
					{
            		//std::cout << "File renaming successful." << std::endl;
            		std::cout << "Registro removido com sucesso." << std::endl;
        			}
				else
					{
            		std::perror("Erro ao renomear.");
        			}
    			}
			else
				{
        		std::perror("Error ao remover.");
				}    
			}
		else
			{
			std::cout << "Resgistro foi mantido, voltaremos ao menu.\n";
			return ;
			}
		}
	}
	
//!!!Nao esta sendo usada!!!
/*void Encontrar_E_Remover_Registro(int chaveProcurada, const std::string& nomeArquivo)
	{
	
    std::ifstream arquivoEntrada(nomeArquivo.c_str());
    std::string linha;// variavel

    bool chaveEncontrada = false; // variavel

     while (std::getline(arquivoEntrada, linha))
	 	{
    	std::istringstream lin(linha);
    	Registro regis;

    	std::string delimiter = " -- ";

    	if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv)
			{

        	//std::cout << "Linha lida: " << linha << "\n";
        	std::cout << "\n Chave encontrada: " << regis.Id_aeronave << "\n";
			std::cout << "\n";

        	if (regis.Id_aeronave == chaveProcurada)
				{
            	chaveEncontrada = true;
            	std::cout << "Registro encontrado:\n";
            	std::cout << "Id_aeronave: " << regis.Id_aeronave << "\n";
            	std::cout << "Matricula_anv: " << regis.Matricula_anv << "\n";
            	std::cout << "Modelo_anv: " << regis.Modelo_anv << "\n";
            	std::cout << "Esquadrao_anv: " << regis.Esquadrao_anv << "\n";
            	std::cout << "Ano_Fabricacao_anv: " << regis.Ano_Fabricacao_anv << "\n";
            	std::cout << "\n\n\n";

				char opcao3;
                std::cout << "Deseja remover este registro? (S/N): ";
                std::cin >> opcao3;

                if (opcao3 == 'S' || opcao3 == 's')
					{
					arquivoEntrada.close();
                    Remover_Registro(chaveProcurada, nomeArquivo);
                    
                    }
                else
					{
					std::cout << "Resgistro foi mantido, voltaremos ao menu.\n";
					break;
					}
        		}
    		}

		else
			{
            std::cerr << "Erro ao ler a linha: " << linha << "\n";
        	}
    	}
    arquivoEntrada.close();
    if (!chaveEncontrada)
		{
        std::cout << "Chave nao encontrada.\n";
    	}
	}*/
	
// OK
void Editar_Campo_Registro(int chaveProcurada, const std::string& nomeArquivo) 
	{
    std::ifstream arquivoEntrada(nomeArquivo.c_str());
    std::ofstream arquivoTemp("temp.txt");

    std::string linha;
    bool chaveEncontrada = false;

    while (std::getline(arquivoEntrada, linha)) // leitura de linhas de texto de arquivos
		{
        std::istringstream lin(linha);
        Registro regis;

        std::string delimiter = " -- ";

        if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv >> delimiter >> regis.Horas_de_voo) 
			{
            //std::cout << "\n Chave encontrada: " << regis.Id_aeronave << "\n";
            //std::cout << "\n";

            if (regis.Id_aeronave == chaveProcurada) 
				{
                chaveEncontrada = true;
                std::cout << "Registro encontrado:\n";
                std::cout << "Id_aeronave: " << regis.Id_aeronave << "\n";
                std::cout << "Matricula_anv: " << regis.Matricula_anv << "\n";
                std::cout << "Modelo_anv: " << regis.Modelo_anv << "\n";
                std::cout << "Esquadrao_anv: " << regis.Esquadrao_anv << "\n";
                std::cout << "Ano_Fabricacao_anv:" << regis.Ano_Fabricacao_anv << "\n\n";
				std::cout << "\n\n";
				
                // Solicitar ao usu�rio o campo a ser editado
                int campoParaEditar;
                std::cout <<"Digite o numero do campo a ser editado:\n ";
				std::cout <<"1 - Matricula\n";
				std::cout <<" 2 - Modelo\n";
				std::cout <<" 3 - Esquadrao\n";
				std::cout <<" 4 - Ano de Fabricacao\n";
                std::cin >> campoParaEditar;

				std::string novoValor1;
				int novoValor2;
                
				// Solicitar ao usu�rio o novo valor para o campo
                if(campoParaEditar>=1 && campoParaEditar<=3 )
					{
                	std::cout << "Digite o novo valor para o campo: ";
                	std::cin >>novoValor1;
					}
					        
				else if(campoParaEditar == 4)
					{
                	std::cout << "Digite o novo valor para o campo: ";
                	std::cin >>novoValor2;
					}
				else
					{
					std::cout << " ";
					}
                // Atualizar o campo correspondente
                switch (campoParaEditar) 
					{
                    case 1:
                        regis.Matricula_anv = novoValor1;
                        break;
                    case 2:
                        regis.Modelo_anv = novoValor1;
                        break;
                    case 3:
                        regis.Esquadrao_anv = novoValor1;
                        break;
                    case 4:
                        regis.Ano_Fabricacao_anv = novoValor2;
                        break;
                    default:
                        std::cerr << "Campo invalido.\n";
                        break;
                	}

                // Escrever o registro atualizado no arquivo temporario
                std::string delimiter = " -- ";
                arquivoTemp << regis.Id_aeronave << delimiter << regis.Matricula_anv << delimiter << regis.Modelo_anv << delimiter
                             << regis.Esquadrao_anv << delimiter << regis.Ano_Fabricacao_anv << delimiter << regis.Horas_de_voo << "\n";
            	} 
			else
				{
                arquivoTemp << linha << "\n";
            	}
        	}
		else
			{
            std::cerr << "Erro ao ler a linha: " << linha << "\n";
        	}
    	}

    arquivoEntrada.close();
    arquivoTemp.close();

    if (chaveEncontrada) 
    	{
        // Remover o arquivo original
        if (std::remove(nomeArquivo.c_str()) == 0) 
        	{
            // Renomear o arquivo temporário para o nome original
            if (std::rename("temp.txt", nomeArquivo.c_str()) == 0) 
            	{
                std::cout << "Edição do campo do registro bem-sucedida.\n";
            	} 
            else 
           		{
                std::perror("Erro ao renomear o arquivo.");
            	}
        	} 
        else 
        	{
            std::perror("Erro ao remover o arquivo original.");
        	}
    	} 
    else
    	{
        std::cout << "Chave não encontrada.\n";
    	}
	}
		
//OK	
int Edita_horas(int chaveProcurada, const std::string& nomeArquivo)
	{
    std::ifstream arquivoEntrada(nomeArquivo.c_str());
    std::ofstream arquivoTemp("temp.txt");

    std::string linha;
    bool chaveEncontrada = false;

    while (std::getline(arquivoEntrada, linha)) // leitura de linhas de texto de arquivos
		{
        std::istringstream lin(linha);
        Registro regis;

        std::string delimiter = " -- ";

        if (lin >> regis.Id_aeronave >> delimiter >> regis.Matricula_anv >> delimiter >> regis.Modelo_anv >> delimiter >> regis.Esquadrao_anv >> delimiter >> regis.Ano_Fabricacao_anv >> delimiter >> regis.Horas_de_voo) 
			{
            //std::cout << "\n Chave encontrada: " << regis.Id_aeronave << "\n";
            //std::cout << "\n";

            if (regis.Id_aeronave == chaveProcurada) 
				{
                chaveEncontrada = true;
                std::cout << "Registro encontrado:\n";
                std::cout << "Id_aeronave: " << regis.Id_aeronave << "\n";
                std::cout << "Matricula_anv: " << regis.Matricula_anv << "\n";
                std::cout << "Modelo_anv: " << regis.Modelo_anv << "\n";
                std::cout << "Esquadrao_anv: " << regis.Esquadrao_anv << "\n";
                std::cout << "Ano_Fabricacao_anv:" << regis.Ano_Fabricacao_anv << "\n";
                std::cout << "HORAS DE VOO :" << regis.Horas_de_voo << "\n\n";
				std::cout << "\n\n";
				
				int opcao5;
                std::cout <<"O que desaja fazer ?\n\n ";
				std::cout <<"1 - Acrescentar (+)\n";
				std::cout <<" 2 - Decrementar (-)\n";
				std::cin >>opcao5;
				
				if (opcao5 == 1)
					{
					int tempo_mais;
					std::cout <<"Acrescentar quantas horas ? ";
					std::cin >>tempo_mais;
					regis.Horas_de_voo += tempo_mais;
					
					int opcao6;
					std::cout <<"Confirmar novo registro de horas :  "<< regis.Horas_de_voo << "\n";
					std::cout <<"1 - CONFIRMAR \n";
					std::cout <<"2 - NEGAR \n";
					std::cin >>opcao6;
					
					if(opcao6 == 1)
						{
						std::cout <<"Registro de horas concluido com sucesso. \n  ";
						}
					else if (opcao6 == 2)
						{
						regis.Horas_de_voo-=tempo_mais;
						std::cout <<"As horas da aeronave nao foram alteradas. \n  ";
						}
					else
						{
						std::cout <<"Opcao invalida \n";
						return 0;
						}
					}
				else if (opcao5 == 2)
					{
					int tempo_menos;
					std::cout <<"Decrementar quantas horas ? ";
					std::cin >>tempo_menos;
					regis.Horas_de_voo -= tempo_menos;
					
					int opcao7;
					std::cout <<"Confirmar novo registro de horas :  "<< regis.Horas_de_voo << "\n";
					std::cout <<"1 - CONFIRMAR \n";
					std::cout <<"2 - NEGAR \n";
					std::cin >>opcao7;
					
					if(opcao7 == 1)
						{
						std::cout <<"Registro de horas concluido com sucesso. \n  ";
						}
					else if (opcao7 == 2)
						{
						regis.Horas_de_voo+=tempo_menos;
						std::cout <<"As horas da aeronave nao foram alteradas. \n  ";
						}
					else
						{
						std::cout <<"Opcao invalida \n";
						return 0;
						}
					
					if(regis.Horas_de_voo < 0)
						{
						regis.Horas_de_voo = 0;
						std::cout <<"Aeronave com horas ZERADAS. \n";
					 	}
					}
				else
					{
					std::cout <<"Opcao invalida \n";
					return 0;
					}
					
					
				std::string delimiter = " -- ";
                arquivoTemp << regis.Id_aeronave << delimiter << regis.Matricula_anv << delimiter << regis.Modelo_anv << delimiter
                             << regis.Esquadrao_anv << delimiter << regis.Ano_Fabricacao_anv << delimiter << regis.Horas_de_voo << "\n";
            	} 
			else
				{
                arquivoTemp << linha << "\n";
            	}
        	}
		else
			{
            std::cerr << "Erro ao ler a linha: " << linha << "\n";
        	}
    	}

    arquivoEntrada.close();
    arquivoTemp.close();

    if (chaveEncontrada) 
		{
        // Remover o arquivo original
        std::string Remocao = "powershell Remove-Item -Path \"" + nomeArquivo + "\" -Force";
        int removeResult = system(Remocao.c_str());

        if (removeResult == 0) 
			{
            // Renomear o arquivo tempor�rio para o nome original
            std::string Renomear = "powershell Rename-Item -Path \"temp.txt\" -NewName \"" + nomeArquivo + "\" -Force";
            int renameResult = system(Renomear.c_str());

            if (renameResult == 0) 
				{
                std::cout << "Edicao do campo do registro bem-sucedida.\n";
            	}
			else
				{
                std::perror("Erro ao renomear o arquivo.");
            	}
        	}
		else 
			{
            std::perror("Erro ao remover o arquivo original.");
        	}
    	}
	else
		{
        std::cout << "Chave n�o encontrada.\n";
    	}
	}
	
	
//OK	
int Novo_Registro_aleatorio(std::string matricula, std::string modelo, std::string esquadrao,int ano, int horas)
	{
	 if (Se_Arquivo_Esta_Vazio("Banco_de_Registros.txt"))
    	{
        std::cout << "Nao ha arquivo em utilizacao ainda.\n O usuario precisa criar um novo Banco de dados . \n";
        return 0;
    	}
    
	int ultimoId = Obter_Ultimo_Id("Banco_de_Registros.txt");
	ultimoId = ultimoId + 1;
		
	
				//new Registro (ultimoId ,matricula, modelo, esquadrao, ano, horas);
				Salva_Em_Arquivo("Banco_de_Registros.txt", ultimoId, matricula, modelo, esquadrao, ano, horas);
	return 1;
	}

//OK	
void registros_aleatorios(int quantidade, const std::string& nomeArquivo) 
	{
    std::srand(std::time(0));
    for (int i = 0; i < quantidade; ++i)
		{
        // Gera valores aleatórios para os campos
        
        std::string matricula = "FAB" + std::to_string(std::rand() % 1000);
        std::string modelo = "Modelo" + std::to_string(std::rand() % 100);
        std::string esquadrao = "Esquadrao" + std::to_string(std::rand() % 10);
        int ano = 2000 + std::rand() % 24; 
        int horas = std::rand() % 5000;    // Exemplo: horas entre 0 e 5000

        // Chama a função Novo_Registro para criar o registro aleatório
        Novo_Registro_aleatorio(matricula, modelo, esquadrao, ano, horas);
    	}
	}	










