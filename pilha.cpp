#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <iostream>
	
//CRIA ESTRUTURA DE UMA PILHA
struct pilha{
	
	int topo;
	int capacidade;
	float *pElem;
	
};

pilha p;

//FUNÇÃO PARA CRIA UMA PILHA
void criaPilha (struct pilha *p, int c){
	p -> topo -1;
	p -> capacidade = c;
	p -> pElem = (float*) malloc (c *sizeof(float));
}


//FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ VAZIA
int verificaPilhaVazia (struct pilha*p){
	if (p -> topo == -1 ){
		return 1;
	}
	else{
		return 0;
	}
}

//FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ CHEIA
int verificaPilhaCheia(struct pilha*p) {
	if(p->topo == p->capacidade -1){
		return 1;
	}else{
		return 0;
	}
}

//FUNÇÃO PARA ADICIONAR A PILHA
void empilha (struct pilha*p, float n ){
	p-> topo++;
	
	p->pElem[p->topo] = n;
	
}

//FUNÇÃO PARA RETIRAR DA PILHA
float desempilha (struct pilha*p){
	p-> topo--;
	
	float gerenciaPilha = p->pElem[p->topo];
	
	return gerenciaPilha;
	
}

//
float retornaAoTopo(struct pilha*p) {
	return p->pElem [p->topo];
}

int main() {
	struct pilha pilha;
	int capacidade = 0;
	int opcao = 0;
	float valor = 0.0;
	
	std::cout << "Digite a capacidade da pilha: ";
	std::cin >> capacidade;
	capacidade = capacidade +1;
	criaPilha (&pilha, capacidade);
	
	
	while (1){
		std::cout << "\n1)Empilhar\n";
		std::cout << "2)Desempilhar\n";
		std::cout << "3)Mostrar topo da pilha\n";
		std::cout << "4)Sair\n";
		std::cout << "\nDigite a opcao desejada: ";
		std::cin >> opcao;
		
		switch(opcao){
			//empilha
			case 1: 
				if (verificaPilhaCheia(&pilha) == 1){
					std::cout << "\nA pilha esta cheia!\n";
				}else{
					std::cout << "Digite o valor: ";
					std::cin >> valor;
					empilha(&pilha, valor);
				}
				break;
			//desempilha
			case 2:
				if (verificaPilhaVazia(&pilha) == 1){
					std::cout << "\nA pilha esta vazia!\n";
				}else{
					valor = desempilha(&pilha);
					std::cout << "\nFoi desempilhado!\n";
				}
				break;
			//mostra o topo da lista
			case 3:
				if (verificaPilhaVazia(&pilha) == 1){
					std::cout << "\nA pilha esta vazia!\n";
				}else{
					valor = retornaAoTopo(&pilha);
					std::cout << "\nO topo da pilha e: " << valor << "\n";
				}
				break;
			//sai do loop
			case 4:
				exit(0);
				break;
		}
		
	}
	
}