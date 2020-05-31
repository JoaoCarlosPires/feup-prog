#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <ctime>

using namespace std;

int clientes(string &cli_agency) { // Função para a opção Gestão de Clientes
	
	int value = 0;
	
	ifstream cli_file;
	ofstream cli_file_out;

	cli_file.open(cli_agency);
	

	if (cli_file.fail()) { // Leitura e verificação de validade do ficheiro dos clientes da agência
			cerr << "\nO ficheiro '" << cli_agency << "' nao existe." << endl;
			exit(1);
		} 
	
	
	typedef struct // Estrutura para definir o cliente
	{
		string nome;
		int nif;
		int agregado;
		string add;
		string pack_list;
	} Client;

	vector<Client> clientes;
	string line;
	Client cliente;
	
	while (!cli_file.eof()) { // Extração dos dados de cada cliente recorrendo a um vetor e à estrutura definida
		getline(cli_file, cliente.nome);
		getline(cli_file, line);
		cliente.nif = stoi(line);
		getline(cli_file, line);
		cliente.agregado = stoi(line);
		getline(cli_file, cliente.add);
		getline(cli_file, cliente.pack_list);
		clientes.push_back(cliente);
		getline(cli_file, line);
	}

	// Menu dos clientes

	cout << "\n Qual das seguintes funcionaliades pretende usar?\n\n";
	cout << "\t1. Adicionar um novo cliente \n";
	cout << "\t2. Alterar as informacoes de um cliente \n";
	cout << "\t3. Remover um cliente \n";
	cout << "\t4. Visualizar a informacao de um cliente \n";
	cout << "\t5. Visualizar a informacao de todos os clientes \n" << endl;
	cout << "(Por favor insira um valor entre 1 e 5)\n" << endl;
	
	while (value != 1 && value != 2 && value != 3 && value != 4 && value != 5) { // Verificação da validade do valor introduzido
		cin >> value;
		if (value != 1 && value != 2 && value != 3 && value != 4 && value != 5) {
			cout << "\nPor favor introduza um valor entre 1 e 5\n" << endl;
		}
	}

	cout << endl;
	cin.ignore(1000, '\n');
	
	if (value == 1) { // Adicionar um novo cliente
		cli_file_out.open(cli_agency);
		
		int i;
		string Nome, Add, Pack_list, NIF, Agregado; 
		
		for (i=0; i <= clientes.size()-1; i++) {
			cli_file_out << clientes[i].nome << endl;
			cli_file_out << clientes[i].nif << endl;
			cli_file_out << clientes[i].agregado << endl;
			cli_file_out << clientes[i].add << endl;
			cli_file_out << clientes[i].pack_list << endl;
			cli_file_out << "::::::::::" << endl;
		}
		
		// Obtenção dos dados do novo cliente

		cout << "Nome? ";
		getline(cin, Nome);
		
		cout << "NIF? ";
		getline(cin, NIF);
		
		cout << "Numero de pessoas do agregado familiar? ";
		getline(cin, Agregado);
		
		cout << "Morada? ";
		getline(cin, Add);
		
		cout << "Quais os packs ja adquiridos? ";
		getline(cin, Pack_list);

		cli_file_out << Nome << "\n" << NIF << "\n" << Agregado << "\n" << Add << "\n" << Pack_list;

		cli_file_out.close();
	}

	if (value == 2) { // Alterar as informações de um cliente
		cli_file_out.open(cli_agency);
		
		int i, num = 0;
		string Nome;
		
		cout << "Qual o nome do cliente cujas informacoes pretende alterar? ";
		getline(cin, Nome);
		
		for (i = 0; i <= clientes.size() - 1; i++) {
			if (clientes[i].nome != Nome) {
				cli_file_out << clientes[i].nome << endl;
				cli_file_out << clientes[i].nif << endl;
				cli_file_out << clientes[i].agregado << endl;
				cli_file_out << clientes[i].add << endl;
				cli_file_out << clientes[i].pack_list << endl;
				if (i == clientes.size() - 1) {continue;}	
				else {cli_file_out << "::::::::::" << endl;}
			} else {
				string new_nome, new_nif, new_agregado, new_add, new_pack_list;
				
				cout << "Qual o novo Nome que pretende? ";
				getline(cin, new_nome);
				cli_file_out << new_nome << endl;
				
				cout << "Qual o novo NIF que pretende? ";
				getline(cin, new_nif);
				cli_file_out << new_nif << endl;
				
				cout << "Qual o novo numero de elementos do agregado familiar que pretende? ";
				getline(cin, new_agregado);
				cli_file_out << new_agregado << endl;
				
				cout << "Qual a nova morada que pretende? ";
				getline(cin, new_add);
				cli_file_out << new_add << endl;
				
				cout << "Qual o novo pack list que pretende? ";
				getline(cin, new_pack_list);
				cli_file_out << new_pack_list << endl;
				 
				num += 1;

				if (i == clientes.size() - 1) {continue;}
				else {cli_file_out << "::::::::::" << endl;}
			}
		}
		if (num != 1) { // Verificação da presença do cliente na base de dados
			cout << "O cliente " << Nome << " nao se encontra na base de dados.";
		}
		
		cli_file_out.close();
	}

	if (value == 3) { // Remover um cliente
		cli_file_out.open(cli_agency);
		
		int i, num = 0;
		string nome;
		
		cout << "Qual o nome do cliente que pretende remover? ";
		getline(cin, nome);

		for (i = 0; i <= clientes.size() - 1; i++) {
			if (clientes[i].nome == nome) {
				num += 1;
				continue;
			}
			else {
				cli_file_out << clientes[i].nome << endl;
				cli_file_out << clientes[i].nif << endl;
				cli_file_out << clientes[i].agregado << endl;
				cli_file_out << clientes[i].add << endl;
				cli_file_out << clientes[i].pack_list << endl;
				if (i == clientes.size() - 1) { continue; }
				if (i == clientes.size() - 2 && clientes[clientes.size() - 1].nome == nome) { continue; }
				else { cli_file_out << "::::::::::" << endl; }
			}
		}

		// Verificação da presença do cliente que se pretende remover na base de dados

		if (num != 1) { cout << "O cliente " << nome << " nao se encontra na base de dados."; }
		else { cout << "O cliente " << nome << " foi removido com sucesso.\n"; }

		cli_file_out.close();
	}

	if (value == 4) { // Visualizar a informacao de um cliente
		int i, num = 0;
		string Nome;
		
		cout << "Qual o nome do cliente que pretende procurar? ";
		getline(cin, Nome);
		
		for (i = 0; i <= clientes.size() - 1; i++) {
			if (clientes[i].nome == Nome) {
				cout << "As informacoes do seu cliente sao:\n";
				cout << "\n\tNome: " << clientes[i].nome << endl;
				cout << "\tNIF: " << clientes[i].nif << endl;
				cout << "\tNumero de elementos do agregado familiar: " << clientes[i].agregado << endl;
				replace(clientes[i].add.begin(), clientes[i].add.end(), '/', ',');
				cout << "\tMorada: " << clientes[i].add << endl;
				cout << "\tLista de packs adquiridos: " << clientes[i].pack_list << endl;
				num += 1;
			}
		}
		if (num != 1) { // Verificação da presença do cliente na base de dados
			cout << "O cliente " << Nome << " nao se encontra na base de dados.";
		}
	}

	if (value == 5) { // Visualizar a informacao de todos os clientes
		int i;
		
		for (i = 0; i <= clientes.size() - 1; i++) {
			cout << "\n\tNome: " << clientes[i].nome << endl;
			cout << "\tNIF: " << clientes[i].nif << endl;
			cout << "\tNumero de elementos do agregado familiar: " << clientes[i].agregado << endl;
			replace(clientes[i].add.begin(), clientes[i].add.end(), '/', ',');
			cout << "\tMorada: " << clientes[i].add << endl;
			cout << "\tLista de packs adquiridos: " << clientes[i].pack_list << endl;
		}
	}

	cli_file.close();

	return 0;
}

int pacotes(string &pack_agency) { // Função para a opção Gestão de Pacotes Turísticos
	int val = 0;

	ifstream age_file;
	ofstream age_file_out;

	age_file.open(pack_agency);


	if (age_file.fail()) { // Leitura e verificação de validade do ficheiro dos pacotes da agência
		cout << "\nO ficheiro '" << pack_agency << "' nao existe." << endl;
		exit(1);
	}

	typedef struct // Estrutura para definir os pacotes da agência
	{
		int number;
		string destination;
		string partida;
		string chegada;
		int preco_pessoa;
		int packs_ini;
		int packs_comp;
		
	} Packs;

	vector<Packs> pacotes;
	string line;
	int i = 0, last_pack;
	Packs pacote;

	while (!age_file.eof()) { // Extração dos dados de cada pacote recorrendo a um vetor e à estrutura definida
		if (i == 0) {
			getline(age_file, line);
			last_pack = stoi(line);
		}
		getline(age_file, line);
		pacote.number = stoi(line);
		getline(age_file, pacote.destination);
		getline(age_file, pacote.partida);
		getline(age_file, pacote.chegada);
		getline(age_file, line);
		pacote.preco_pessoa = stoi(line);
		getline(age_file, line);
		pacote.packs_ini = stoi(line);
		getline(age_file, line); 
		pacote.packs_comp = stoi(line);
		pacotes.push_back(pacote);
		getline(age_file, line);
		i += 1;
	}


	// Menu dos pacotes

	cout << "\n Qual das seguintes funcionaliades pretende usar?\n\n";
	cout << "\t1. Adicionar um novo pacote \n";
	cout << "\t2. Alterar as informacoes de um pacote \n";
	cout << "\t3. Remover um pacote \n";
	cout << "\t4. Visualizar a informacao de um determinado pacote \n";
	cout << "\t5. Visualizar a informacao de todos os pacotes \n" << endl; 
	cout << "(Por favor insira um valor entre 1 e 5)\n" << endl;

	while (val != 1 && val != 2 && val != 3 && val != 4 && val != 5) { // Verificação da validade do valor introduzido
		cin >> val;
		if (val != 1 && val != 2 && val != 3 && val != 4 && val != 5) {
			cout << "\nPor favor introduza um valor entre 1 e 5" << endl << endl;
		}
	}

	cout << endl;
	cin.ignore(1000, '\n');

	if (val == 1) { // Adicionar um novo pacote
		age_file_out.open(pack_agency);

		int i;
		string Number, Destination, Partida, Chegada, Preco_pessoa, Packs_ini, Packs_comp;

		cout << "Numero do pacote? ";
		getline(cin, Number);

		cout << "Destino? ";
		getline(cin, Destination);

		cout << "Data de partida? (Formato YYYY/MM/DD) ";
		getline(cin, Partida);

		cout << "Data de chegada? (Formato YYYY/MM/DD) ";
		getline(cin, Chegada);

		cout << "Preco por pessoa? ";
		getline(cin, Preco_pessoa);

		cout << "Packs inicialmente disponiveis? ";
		getline(cin, Packs_ini);

		cout << "Packs disponiveis? ";
		getline(cin, Packs_comp);

		if (Packs_ini < Packs_comp) { // Verificação da validade do número de packs introduzidos
			cout << "O numero de packs disponiveis inicialmente nao pode ser inferior ao numero de packs comprados.";
			exit(1);
		}
		if (Packs_ini == Packs_comp) { // Se já não existirem mais packs em stock, o número do pack passa a ser negativo
			Number = '-' + Number;
		}

		age_file_out << Number << "\n";

		for (i = 0; i <= pacotes.size() - 1; i++) {
			age_file_out << pacotes[i].number << endl;
			age_file_out << pacotes[i].destination << endl;
			age_file_out << pacotes[i].partida << endl;
			age_file_out << pacotes[i].chegada << endl;
			age_file_out << pacotes[i].preco_pessoa << endl;
			age_file_out << pacotes[i].packs_ini << endl;
			age_file_out << pacotes[i].packs_comp << endl;
			age_file_out << "::::::::::" << endl;
		}
		
		age_file_out << Number << "\n" << Destination << "\n" << Partida << "\n" << Chegada << "\n" << Preco_pessoa << "\n" << Packs_ini << "\n" << Packs_comp;

		cout << "\nO novo pacote foi adicionado com sucesso!" << endl;

		age_file_out.close();
	}

	if (val == 2) { // Alterar as informacoes de um pacote
		age_file_out.open(pack_agency);

		int num;

		cout << "Qual o numero do pacote que pretende alterar? ";
		cin >> num;

		string Destination, Partida, Chegada, Preco_pessoa, Packs_ini, Packs_comp;
		int Number;

		cout << "Qual o novo numero do pacote? ";
		cin >> Number;

		cout << "Qual o novo destino? " << endl;
		cin >> Destination;

		cout << "Qual a nova data de partida? (Formato YYYY/MM/DD) " << endl;
		cin >> Partida;

		cout << "Qual a nova data de chegada? (Formato YYYY/MM/DD) " << endl;
		cin >> Chegada;

		cout << "Qual o novo preco por pessoa? " << endl;
		cin >> Preco_pessoa;

		cout << "Qual o novo numero de packs iniciais? " << endl;
		cin >> Packs_ini;

		cout << "Qual o novo numero de packs adquiridos? " << endl;
		cin >> Packs_comp;

		if (Packs_ini < Packs_comp) { // Verificação da validade do número de packs introduzidos
			cout << "\nO numero de packs disponiveis inicialmente nao pode ser inferior ao numero de packs comprados." << endl;
			exit(1);
		}
		if (Packs_ini == Packs_comp) { // Se já não existirem mais packs em stock, o número do pack passa a ser negativo
			Number = -Number;
		}

		if (pacotes[pacotes.size() - 1].number == num) {
			age_file_out << Number << endl;
		}	else {
			age_file_out << pacotes[pacotes.size() - 1].number << endl;
		}

		int val = 0;

		for (i = 0; i <= pacotes.size() - 1; i++) {
			if (num == pacotes[i].number) {

				val += 1;

				age_file_out << Number << endl;
				age_file_out << Destination << endl;
				age_file_out << Partida << endl;
				age_file_out << Chegada << endl;
				age_file_out << Preco_pessoa << endl;
				age_file_out << Packs_ini << endl;
				age_file_out << Packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				age_file_out << "::::::::::" << endl;

			}	else {

				age_file_out << pacotes[i].number << endl;
				age_file_out << pacotes[i].destination << endl;
				age_file_out << pacotes[i].partida << endl;
				age_file_out << pacotes[i].chegada << endl;
				age_file_out << pacotes[i].preco_pessoa << endl;
				age_file_out << pacotes[i].packs_ini << endl;
				age_file_out << pacotes[i].packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				age_file_out << "::::::::::" << endl;
			}
		}

		if (val == 0) { // Verificação da existência do pacote através do número obtido no input do utilizador
			cout << "\nO numero do que introduziu nao esta associado a nenhum pacote." << endl;
		} else {
			cout << "\nAlteracao efetuada com sucesso!" << endl;
		}

		age_file_out.close();
	}

	if (val == 3) { // Remover um pacote
		age_file_out.open(pack_agency);

		int num, val = 0;

		cout << "Qual o numero do pacote que pretende remover? ";
		cin >> num;

		if (num == pacotes[pacotes.size() - 1].number) {
			age_file_out << pacotes[pacotes.size() - 2].number << endl;
		} else {
			age_file_out << pacotes[pacotes.size() - 1].number << endl;
		}

		for (i = 0; i <= pacotes.size() - 1; i++) {
			if (pacotes[i].number == num) {
				val += 1;
				continue;
			}
			else {
				age_file_out << pacotes[i].number << endl;
				age_file_out << pacotes[i].destination << endl;
				age_file_out << pacotes[i].partida << endl;
				age_file_out << pacotes[i].chegada << endl;
				age_file_out << pacotes[i].preco_pessoa << endl;
				age_file_out << pacotes[i].packs_ini << endl;
				age_file_out << pacotes[i].packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				if (num == pacotes[pacotes.size() - 1].number && i == pacotes.size() - 2) {
					continue;
				}
				age_file_out << "::::::::::" << endl;
			}
		}

		if (val == 0) { // Verificação da existência do pacote através do número obtido no input do utilizador
			cout << "\nO numero que introduziu nao corresponde a nenhum pacote." << endl;
		} else {
		cout << "\nO pacote " << num << " foi removido com sucesso!" << endl;
		}

		age_file_out.close();
	}

	if (val == 4) { // Visualizar a informacao de um determinado pacote
		
		age_file_out.open(pack_agency);

		// Sub-menu da funcionalidade de visualização de informações dos pacotes turísticos

		cout << "\n Qual das seguintes funcionaliades pretende usar?\n\n";
		cout << "\t1. Visualizar todos os pacotes para um destino \n";
		cout << "\t2. Visualizar todos os pacotes entre duas datas \n";
		cout << "\t3. Visualizar todos os pacotes para um destido entre duas datas \n";
		cout << "(Por favor insira um valor entre 1 e 3)\n" << endl;

		int num = 0;

		while (num != 1 && num != 2 && num != 3) { // Verificação da validade do valor introduzido
			cin >> num;
			if (num != 1 && num != 2 && num != 3) {
				cout << "\nPor favor introduza um valor entre 1 e 3" << endl << endl;
			}
		}

		cout << endl;
		cin.ignore(1000, '\n');

		if (num == 1) { // Visualizar todos os pacotes para um destino
			
			string destino;
			int vali = 0;

			cout << "Qual o destino que pretende? ";
			cin >> destino;
			
			cout << "\n";

			for (i = 0; i <= pacotes.size() - 1; i++) {
				if (pacotes[i].destination == destino) {
					cout << "\tNumero do pacote: " << pacotes[i].number << endl;
					cout << "\tDestino: " << pacotes[i].destination << endl;
					cout << "\tData de partida: " << pacotes[i].partida << endl;
					cout << "\tData de chegada: " << pacotes[i].chegada << endl;
					cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
					cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
					cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
					cout << "\n";
					vali += 1;
				}	else {
					continue;
				}
			}

			if (vali == 0) { // Verificação da existência de pacotes para um determinado destino
				cout << "Nao existem pacotes para " << destino << ".";
			}
			
			age_file_out << pacotes[pacotes.size() - 1].number << endl;

			for (i = 0; i <= pacotes.size() - 1; i++) {
				age_file_out << pacotes[i].number << endl;
				age_file_out << pacotes[i].destination << endl;
				age_file_out << pacotes[i].partida << endl;
				age_file_out << pacotes[i].chegada << endl;
				age_file_out << pacotes[i].preco_pessoa << endl;
				age_file_out << pacotes[i].packs_ini << endl;
				age_file_out << pacotes[i].packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				age_file_out << "::::::::::" << endl;
			}

		}

		if (num == 2) { // Visualizar todos os pacotes entre duas datas

			string data_partida, data_chegada;
			int vali = 0;

			cout << "Qual a data de partida que pretende? (Formato YYYY/MM/DD) ";
			cin >> data_partida;
			cout << "Qual a data de chegada que pretende? (Formato YYYY/MM/DD) ";
			cin >> data_chegada;


			cout << "\n";

			vector<string> data1;
			string data1_1;

			vector<string> data2;
			string data2_2;

			for (char& c : data_partida) { // Obtenção do ano, mês e dia da data de partida do utilizador
				if (c == '/') {
					data1.push_back(data1_1);
					data1_1 = "";
				}
				else {
					data1_1 += c;
				}
			}
			data1.push_back(data1_1);

			for (char& c : data_chegada) { // Obtenção do ano, mês e dia da data de chegada do utilizador
				if (c == '/') {
					data2.push_back(data2_2);
					data2_2 = "";
				}
				else {
					data2_2 += c;
				}
			}
			data2.push_back(data2_2);

			vector<string> data3;
			vector<string> data4;

			for (i = 0; i <= pacotes.size() - 1; i++) {

				string data3_3 = "";
				string data4_4 = "";

				for (char& c : pacotes[i].partida) { // Obtenção do ano, mês e dia da data de partida do pacote
					if (c == '/') {
						data3.push_back(data3_3);
						data3_3 = "";
					}
					else {
						data3_3 += c;
					}
				}
				data3.push_back(data3_3);

				for (char& c : pacotes[i].chegada) { // Obtenção do ano, mês e dia da data de chegada do pacote
					if (c == '/') {
						data4.push_back(data4_4);
						data4_4 = "";
					}
					else {
						data4_4 += c;
					}
				}
				data4.push_back(data4_4);

				// Condições para verificação dos pacotes dispóníveis entre as datas introduzidas pelo utilizador

				if (data1[0] == data3[0] && data2[0] == data4[0]) { 
					if (data1[1] == data3[1] && data2[1] == data4[1]) {
						if (data1[2] <= data3[2] && data2[2] >= data4[2]) {
							cout << "\tNumero do pacote: " << pacotes[i].number << endl;
							cout << "\tDestino: " << pacotes[i].destination << endl;
							cout << "\tData de partida: " << pacotes[i].partida << endl;
							cout << "\tData de chegada: " << pacotes[i].chegada << endl;
							cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
							cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
							cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
							cout << "\n";
							vali += 1;
						}
					}
				}
				if ((data1[0] == data3[0]) && (data2[0] == data4[0]) && (data1[1] < data3[1]) && (data2[1] > data4[1])) {
						cout << "\tNumero do pacote: " << pacotes[i].number << endl;
						cout << "\tDestino: " << pacotes[i].destination << endl;
						cout << "\tData de partida: " << pacotes[i].partida << endl;
						cout << "\tData de chegada: " << pacotes[i].chegada << endl;
						cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
						cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
						cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
						cout << "\n";
						vali += 1;
				} 
				if ((data1[0] < data3[0]) && (data2[0] > data4[0])) {
					cout << "\tNumero do pacote: " << pacotes[i].number << endl;
					cout << "\tDestino: " << pacotes[i].destination << endl;
					cout << "\tData de partida: " << pacotes[i].partida << endl;
					cout << "\tData de chegada: " << pacotes[i].chegada << endl;
					cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
					cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
					cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
					cout << "\n";
					vali += 1;
				}
	
				data3.clear();
				data4.clear();
			}

			if (vali == 0) { // Verificação da existência de pacotes entre as datas do utilizador
				cout << "Nao existem pacotes entre " << data_partida << " e " << data_chegada << ".";
			}

			age_file_out << pacotes[pacotes.size() - 1].number << endl;

			for (i = 0; i <= pacotes.size() - 1; i++) {
				age_file_out << pacotes[i].number << endl;
				age_file_out << pacotes[i].destination << endl;
				age_file_out << pacotes[i].partida << endl;
				age_file_out << pacotes[i].chegada << endl;
				age_file_out << pacotes[i].preco_pessoa << endl;
				age_file_out << pacotes[i].packs_ini << endl;
				age_file_out << pacotes[i].packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				age_file_out << "::::::::::" << endl;
			}

		}

		if (num == 3) { // Visualizar todos os pacotes para um destido entre duas datas
			
			string data_partida, data_chegada, destino;
			int vali = 0;

			cout << "Qual o destino que pretende? ";
			cin >> destino;
			cout << "Qual a data de partida que pretende? (Formato YYYY/MM/DD) ";
			cin >> data_partida;
			cout << "Qual a data de chegada que pretende? (Formato YYYY/MM/DD) ";
			cin >> data_chegada;

			cout << "\n";

			vector<string> data1;
			string data1_1;

			vector<string> data2;
			string data2_2;

			for (char& c : data_partida) { // Obtenção do ano, mês e dia da data de partida do utilizador 
				if (c == '/') {
					data1.push_back(data1_1);
					data1_1 = "";
				}
				else {
					data1_1 += c;
				}
			}
			data1.push_back(data1_1);

			for (char& c : data_chegada) { // Obtenção do ano, mês e dia da data de chegada do utilizador
				if (c == '/') {
					data2.push_back(data2_2);
					data2_2 = "";
				}
				else {
					data2_2 += c;
				}
			}
			data2.push_back(data2_2);

			vector<string> data3;
			vector<string> data4;

			for (i = 0; i <= pacotes.size() - 1; i++) {

				string data3_3 = "";
				string data4_4 = "";

				for (char& c : pacotes[i].partida) { // Obtenção do ano, mês e dia da data de partida do pacote
					if (c == '/') {
						data3.push_back(data3_3);
						data3_3 = "";
					}
					else {
						data3_3 += c;
					}
				}
				data3.push_back(data3_3);

				for (char& c : pacotes[i].chegada) { // Obtenção do ano, mês e dia da data de chegada do pacote
					if (c == '/') {
						data4.push_back(data4_4);
						data4_4 = "";
					}
					else {
						data4_4 += c;
					}
				}
				data4.push_back(data4_4);

				// Verificação dos pacotes entre as datas do utilizador e para um determinado destino

				if (pacotes[i].destination == destino) {
					if (data1[0] == data3[0] && data2[0] == data4[0]) {
						if (data1[1] == data3[1] && data2[1] == data4[1]) {
							if (data1[2] <= data3[2] && data2[2] >= data4[2]) {
								cout << "\tNumero do pacote: " << pacotes[i].number << endl;
								cout << "\tDestino: " << pacotes[i].destination << endl;
								cout << "\tData de partida: " << pacotes[i].partida << endl;
								cout << "\tData de chegada: " << pacotes[i].chegada << endl;
								cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
								cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
								cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
								cout << "\n";
								vali += 1;
							}
						}
					}
					if ((data1[0] == data3[0]) && (data2[0] == data4[0]) && (data1[1] < data3[1]) && (data2[1] > data4[1])) {
						cout << "\tNumero do pacote: " << pacotes[i].number << endl;
						cout << "\tDestino: " << pacotes[i].destination << endl;
						cout << "\tData de partida: " << pacotes[i].partida << endl;
						cout << "\tData de chegada: " << pacotes[i].chegada << endl;
						cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
						cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
						cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
						cout << "\n";
						vali += 1;
					} 
					if ((data1[0] < data3[0]) && (data2[0] > data4[0])) {
						cout << "\tNumero do pacote: " << pacotes[i].number << endl;
						cout << "\tDestino: " << pacotes[i].destination << endl;
						cout << "\tData de partida: " << pacotes[i].partida << endl;
						cout << "\tData de chegada: " << pacotes[i].chegada << endl;
						cout << "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
						cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
						cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
						cout << "\n";
						vali += 1;
					}
				}

				data3.clear();
				data4.clear();
			}

			if (vali == 0) { // Verificação da existência de pacotes para as restrções impostas pelo utilizador (data e destino)
				cout << "Nao existem pacotes para " << destino <<  " entre " << data_partida << " e " << data_chegada << ".";
			}

			age_file_out << pacotes[pacotes.size() - 1].number << endl;

			for (i = 0; i <= pacotes.size() - 1; i++) {
				age_file_out << pacotes[i].number << endl;
				age_file_out << pacotes[i].destination << endl;
				age_file_out << pacotes[i].partida << endl;
				age_file_out << pacotes[i].chegada << endl;
				age_file_out << pacotes[i].preco_pessoa << endl;
				age_file_out << pacotes[i].packs_ini << endl;
				age_file_out << pacotes[i].packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				age_file_out << "::::::::::" << endl;
			}

		}

		

		age_file_out.close();
	}



	if (val == 5) { // Visualizar a informacao de todos os pacotes
		
		age_file_out.open(pack_agency);

		cout << "\n";
		
		for (i = 0; i <= pacotes.size() - 1; i++) {
			cout << "\tNumero do pacote: " << pacotes[i].number << endl;
			cout << "\tDestino: " << pacotes[i].destination << endl;
			cout << "\tData de partida: " << pacotes[i].partida << endl;
			cout << "\tData de chegada: " << pacotes[i].chegada << endl;
			cout <<  "\tPreco por pessoa: " << pacotes[i].preco_pessoa << endl;
			cout << "\tNumero de packs iniciais: " << pacotes[i].packs_ini << endl;
			cout << "\tNumero de packs comprados: " << pacotes[i].packs_comp << endl;
			cout << "\n";
		}

		age_file_out << pacotes[pacotes.size() - 1].number << endl;

		for (i = 0; i <= pacotes.size() - 1; i++) {
			age_file_out << pacotes[i].number << endl;
			age_file_out << pacotes[i].destination << endl;
			age_file_out << pacotes[i].partida << endl;
			age_file_out << pacotes[i].chegada << endl;
			age_file_out << pacotes[i].preco_pessoa << endl;
			age_file_out << pacotes[i].packs_ini << endl;
			age_file_out << pacotes[i].packs_comp << endl;
			if (i == pacotes.size() - 1) {
				continue;
			}
			age_file_out << "::::::::::" << endl;
		}

		age_file_out.close();
	}

	age_file.close();

	return 0;
}

int compra(string &cli_agency, string &pack_agency) { // Função para a compra e visualização de pacotes turísticos comprados
	
	int value = 0;

	ifstream cli_file;
	ofstream cli_file_out;

	cli_file.open(cli_agency);
	
	if (cli_file.fail()) { // Leitura e verificação de validade do ficheiro dos clientes da agência
		cerr << "\nO ficheiro '" << cli_agency << "' nao existe." << endl;
		exit(1);
	}

	typedef struct // Estrutura para definir o cliente
	{
		string nome;
		int nif;
		int agregado;
		string add;
		string pack_list;
	} Client;

	vector<Client> clientes;
	string line;
	Client cliente;

	while (!cli_file.eof()) { // Extração dos dados de cada cliente recorrendo a um vetor e à estrutura definida
		getline(cli_file, cliente.nome);
		getline(cli_file, line);
		cliente.nif = stoi(line);
		getline(cli_file, line);
		cliente.agregado = stoi(line);
		getline(cli_file, cliente.add);
		getline(cli_file, cliente.pack_list);
		clientes.push_back(cliente);
		getline(cli_file, line);
	}

	ifstream age_file;
	ofstream age_file_out;

	age_file.open(pack_agency);
	
	if (age_file.fail()) { // Leitura e verificação de validade do ficheiro dos pacotes da agência
		cout << "\nO ficheiro '" << pack_agency << "' nao existe." << endl;
		exit(2);
	}

	typedef struct // Estrutura para definir os pacotes da agência
	{
		int number;
		string destination;
		string partida;
		string chegada;
		int preco_pessoa;
		int packs_ini;
		int packs_comp;

	} Packs;

	vector<Packs> pacotes;
	string line2;
	int i = 0, last_pack;
	Packs pacote;

	while (!age_file.eof()) { // Extração dos dados de cada pacote recorrendo a um vetor e à estrutura definida
		if (i == 0) {
			getline(age_file, line2);
			last_pack = stoi(line2);
		}
		getline(age_file, line2);
		pacote.number = stoi(line2);
		getline(age_file, pacote.destination);
		getline(age_file, pacote.partida);
		getline(age_file, pacote.chegada);
		getline(age_file, line2);
		pacote.preco_pessoa = stoi(line2);
		getline(age_file, line2);
		pacote.packs_ini = stoi(line2);
		getline(age_file, line2);
		pacote.packs_comp = stoi(line2);
		pacotes.push_back(pacote);
		getline(age_file, line2);
		i += 1;
	}

	// Menu Compra

	cout << "\n Qual das seguintes funcionaliades pretende usar?\n\n";
	cout << "\t1. Comprar um pacote turistico para um cliente \n";
	cout << "\t2. Visualizar pacotes vendidos a um cliente \n";
	cout << "\t3. Visualizar pacotes vendidos a todos os clientes \n";
	cout << "\t4. Visualizar o numero de pacotes vendidos e o valor total \n";
	cout << "(Por favor insira um valor entre 1 e 4)\n" << endl;

	while (value != 1 && value != 2 && value != 3 && value != 4) { // Verificação da validade do valor introduzido
		cin >> value;
		if (value != 1 && value != 2 && value != 3 && value != 4) {
			cout << "\nPor favor introduza um valor entre 1 e 4\n" << endl;
		}
	}

	cout << endl;
	cin.ignore(1000, '\n');

	if (value == 1) { // Comprar um pacote turistico para um cliente

		age_file_out.open(pack_agency);
		cli_file_out.open(cli_agency);


		string nome_cli;
		int num_pack, val1 = 0, val2 = 0, cli_num, pack_num;
		
		cout << "Qual o nome do cliente? ";
		getline(cin, nome_cli);

		for (i = 0; i <= clientes.size() - 1; i++) { // Verificação da presença do cliente na base de dados
			if (clientes[i].nome == nome_cli) {
				cli_num = i;
				val1 = 1;
			}
		}

		if (val1 == 0) {
			cerr << "O cliente " << nome_cli << " nao se encontra na base de dados.";
			exit(1);
		}
		
		cout << "Qual o pacote pretendido? (Por favor indique o numero) ";
		cin >> num_pack;

		for (i = 0; i <= pacotes.size() - 1; i++) { // Verificação da presença do pacote turístico na base de dados
			if ( pacotes[i].number == num_pack) {
				pack_num = i;
				val2 = 1;
			}
		}

		if (val2 == 0) {
			cerr << "O pacote " << num_pack << " nao se encontra na base de dados.";
			exit(1);
		}

		// Verificação da possibilidade de adquirir o pacote com base no stock 

		if ((pacotes[pack_num].packs_comp == pacotes[pack_num].packs_ini) || (clientes[cli_num].agregado > ((pacotes[pack_num].packs_ini)-(pacotes[pack_num].packs_comp)))) {
			cerr << "Nao e possivel adquirir o pack. Rutura de stock.";
			age_file_out << last_pack << endl;
			for (i = 0; i <= pacotes.size() - 1; i++) {
				age_file_out << pacotes[i].number << endl;
				age_file_out << pacotes[i].destination << endl;
				age_file_out << pacotes[i].partida << endl;
				age_file_out << pacotes[i].chegada << endl;
				age_file_out << pacotes[i].preco_pessoa << endl;
				age_file_out << pacotes[i].packs_ini << endl;
				age_file_out << pacotes[i].packs_comp << endl;
				if (i == pacotes.size() - 1) {
					continue;
				}
				age_file_out << "::::::::::" << endl;
			}

			for (i = 0; i <= clientes.size() - 1; i++) {
				cli_file_out << clientes[i].nome << endl;
				cli_file_out << clientes[i].nif << endl;
				cli_file_out << clientes[i].agregado << endl;
				cli_file_out << clientes[i].add << endl;
				cli_file_out << clientes[i].pack_list << endl;
				if (i == clientes.size() - 1) {
					continue;
				}
				cli_file_out << "::::::::::" << endl;
			}
			exit(1);
		}

		// Atualização dos dados no ficheiro dos clientes e dos packs

		pacotes[pack_num].packs_comp += clientes[cli_num].agregado;
		
		if (pacotes[pack_num].packs_comp == pacotes[pack_num].packs_ini) {
			pacotes[pack_num].number = '-' + pacotes[pack_num].number;
		}

		clientes[cli_num].pack_list += "; " + to_string(num_pack);

		age_file_out << last_pack << endl;

		for (i = 0; i <= pacotes.size() - 1; i++) {
			age_file_out << pacotes[i].number << endl;
			age_file_out << pacotes[i].destination << endl;
			age_file_out << pacotes[i].partida << endl;
			age_file_out << pacotes[i].chegada << endl;
			age_file_out << pacotes[i].preco_pessoa << endl;
			age_file_out << pacotes[i].packs_ini << endl;
			age_file_out << pacotes[i].packs_comp << endl;
			if (i == pacotes.size() - 1) {
				continue;
			}
			age_file_out << "::::::::::" << endl;
		}

		for (i = 0; i <= clientes.size() - 1; i++) {
			cli_file_out << clientes[i].nome << endl;
			cli_file_out << clientes[i].nif << endl;
			cli_file_out << clientes[i].agregado << endl;
			cli_file_out << clientes[i].add << endl;
			cli_file_out << clientes[i].pack_list << endl;
			if (i == clientes.size() - 1) {
				continue;
			}
			cli_file_out << "::::::::::" << endl;
		}
		
		age_file_out.close();
		cli_file_out.close();
	}
	
	if (value == 2) { // Visualizar pacotes vendidos a um cliente
		
		string user_client;
		int ver = 0;

		cout << "Para qual cliente pretende visualizar os pacotes turisticos adquiridos? ";
		getline(cin, user_client);
		
		for (i = 0; i <= clientes.size() - 1; i++) {
			if (clientes[i].nome == user_client) {
				cout << "\n\tNome: " << clientes[i].nome << endl;
				cout << "\tLista de packs adquiridos: " << clientes[i].pack_list << endl;
				ver = 1;
			}
		}

		if (ver == 0) { // Verificação da existência de um cliente
			cout << "O cliente " << user_client << " não se encontra na base de dados.";
		}
	}

	if (value == 3) { // Visualizar pacotes vendidos a todos os clientes
		for (int i = 0; i <= clientes.size() - 1; i++) {
			cout << "\n\tNome: " << clientes[i].nome << endl;
			cout << "\tLista de packs adquiridos: " << clientes[i].pack_list << endl;
		}
	}
	
	if (value == 4) { // Visualizar o numero de pacotes vendidos e o valor total
		
		int total_v = 0, total_p = 0;
				
		for (int i = 0; i <= pacotes.size() - 1; i++) { // Cálculo do valor total e registo dos packs vendidos
			total_v += pacotes[i].packs_comp * pacotes[i].preco_pessoa;
			total_p += pacotes[i].packs_comp;
		}
		
		cout << "Foram vendidos " << total_p << " pacotes, num valor total de " << total_v << " euros.\n" << endl;
	}
	
	cli_file.close();
	age_file.close();
	
	return 0;
}

int menu(string &cli_agency, string &pack_agency) { // Função com o menu inicial
	
	int numero = 0;
	int num;
	
	cout << "\n\t 1. Gestao de clientes \n \t 2. Gestao de pacotes turisticos \n \t 3. Visualizacao de informacao sobre a agencia \n \t 4. Compra de um pacote turistico" << endl;
	cout << "\nQual a funcionalidade que pretende usar? \n(Por favor digite um numero de 1 a 3)\n\n";
	
	while (numero == 0) { // Verificação da validade do número introduzido
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) {
			numero = 1;
		}	else {
			cout << "Por favor insira um valor entre 1 e 4.";
		}
	}

	if (num == 1) {
		clientes(cli_agency);
	}
	if (num == 2) {
		pacotes(pack_agency);
	}
	if (num == 3) {
		return 3;
	}
	
	if (num == 4) {
		compra(cli_agency, pack_agency);
	}
	return 0;
}

int main() {

	cout << "===============================================" << endl;
	cout << "||      Programa de Agencias de Viagens      ||" << endl;
	cout << "===============================================\n" << endl;
	
	int ver = 0;	
	string file_ini;	
	ifstream agency_file;
	ofstream agency_file_out;
	
	while (ver == 0) { // Ciclo while para leitura e verificação de validade do ficheiro da agência
		cout << "Qual o nome do ficheiro que pretende usar? ";
		getline(cin, file_ini);
		agency_file.open(file_ini);
		if (agency_file.fail()) {	
			ver = 0;
			cerr << "\nPor favor insira um nome de ficheiro valido.\n\n";
		} else {
			ver = 1;
		}
	} 
	
	typedef struct // Estrutura da agência de viagens
	{
		string nome;
		string nif;
		string url;
		string add;
		string client_file;
		string pack_file;
	} Agency;

	vector<Agency> agencias;
	string line;
	Agency agencia;

	while (!agency_file.eof()) { // Leitura e armazenamento das informações da agência de viagens
		getline(agency_file, agencia.nome);
		getline(agency_file, agencia.nif);
		getline(agency_file, agencia.url);
		getline(agency_file, agencia.add);
		getline(agency_file, agencia.client_file);
		getline(agency_file, agencia.pack_file);
	}
	
	string cli_agency, pack_agency;
	
	cli_agency = agencia.client_file;
	pack_agency = agencia.pack_file;
	
	if (menu(cli_agency, pack_agency) == 3) { // Visualização das Informações da Agência
		cout << "\nAs informacoes da agencia sao: \n" << endl;
		cout << "\tAgencia: " << agencia.nome << endl;
		cout << "\tNIF: " << agencia.nif << endl;
		cout << "\tURL: " << agencia.url << endl;
		replace(agencia.add.begin(), agencia.add.end(), '/', ',');
		cout << "\tMorada: " << agencia.add << endl;
	}
  
	agency_file.close();
	
	return 0;
}