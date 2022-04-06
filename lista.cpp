#include <iostream>
#include <list>

using namespace std;

int main(){
	list<int> lista;
	int opc = 0;
	int capacidade = 0;
	int valor = 0;
	int primeiraPos = 0;
	int segundaPos = 0;
	
	cout << "Digite o tamanho da lista: ";
	cin >> capacidade;
	capacidade+=1;
	
	list<int>::iterator it;
	for(int i=0;i<capacidade;i++){
		lista.push_back(i);
	}
	
	int primeiroItem = lista.front();
	int ultimoItem = lista.back();
	
	while (1){
		cout << "\n1)Remover o primeiro item da lista\n";
		cout << "2)Remover o ultimo item da lista\n";
		cout << "3)Mostrar os valores da lista\n";
		cout << "4)Adicionar valor na primeira posicao\n";
		cout << "5)Sair\n";
		cout << "\nDigite a opcao desejada: ";
		cin >> opc;
	
		switch(opc){
			
			case 1: 
				lista.remove(primeiroItem);
				cout << "Removido com sucesso!!\n\n";
				break;
			
			case 2:
				lista.remove(ultimoItem);
				cout << "Removido com sucesso!!\n\n";
				break;
			
			case 3:
				cout << "Digite o valor: ";
				cin >> valor;
				cout << "Inserir entre a posicao: ";
				cin >> primeiraPos;
				cout << "E a posicao: ";
				cin >> segundaPos;
				lista.insert(valor, primeiraPos, segundaPos);
				break;
				
			case 4:
				
				break;
			
			case 5:
				exit(0);
				break;
			
			default:
				cout << "\nAs opcoes sao apenas de 1 a 4!!\n\n";
				break;
		}
	
	}
	
	return 0;
}
