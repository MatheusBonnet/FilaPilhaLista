#include<iostream>

struct Fila {

	int capacidadeDaFila;
	float *dados;
	int primeiroElemento;
	int ultimoElemento;
	int nItens; 

};


void inserir(struct Fila *f, int v) {

	if(f->ultimoElemento == f->capacidadeDaFila-1)
		f->ultimoElemento = -1;

	f->ultimoElemento++;
	f->dados[f->ultimoElemento] = v; // incrementa ultimoElemento e insere
	f->nItens++; // mais um item inserido

}

void criarFila( struct Fila *f, int valor ) { 

	f->capacidadeDaFila = valor;
	f->dados = (float*) malloc (f->capacidadeDaFila * sizeof(float));
	f->primeiroElemento = 0;
	f->ultimoElemento = -1;
	f->nItens = 0; 

}

int remover( struct Fila *f ) { // pega o item do começo da fila

	int temp = f->dados[f->primeiroElemento++]; // pega o valor e incrementa o primeiroElemento

	if(f->primeiroElemento == f->capacidadeDaFila)
		f->primeiroElemento = 0;

	f->nItens--;  // um item retirado
	return temp;

}

// retorna verdadeiro se a fila está vazia
int filaVazia( struct Fila *f ) { 

	return (f->nItens==0);

}

 // retorna verdadeiro se a fila está cheia
int filaCheia( struct Fila *f ) {

	return (f->nItens == f->capacidadeDaFila);
}

void mostrarTodosValoresDaFila(struct Fila *f){

	int cont = 0;
	int i = 0;

	for ( cont=0, i= f->primeiroElemento; cont < f->nItens; cont++){

		std::cout << f->dados[i++];

		if (i == f->capacidadeDaFila)
			i=0;

	}
	printf("\n\n");

}

int main () {

    int opcao, capa;
	float valor;
	struct Fila fila;

	printf("\Sistema de Fila!!! ");
	criarFila(&fila, capa);

	while( 1 ){

		printf("\n1 - Inserir valor na fila\n2 - Remover alguem da fila\n3 - Mostrar todos os valores da fila\n4 - Inserir a capacidade da fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (filaCheia(&fila)){

					printf("\nFila totalmente Cheia!!!\n\n");

				}
				else {

					printf("\nValor a ser inserido? ");
					scanf("%f", &valor);
					inserir(&fila,valor);

				}

				break;

			case 2: // remove elemento
				if (filaVazia(&fila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					valor = remover(&fila);
					printf("\n%1f removido com sucesso\n\n", valor) ; 

				}
				break;

			case 3: // mostrar fila
				if (filaVazia(&fila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					printf("\nConteudo da fila => ");
					mostrarTodosValoresDaFila(&fila);

				}
				break;
			case 4:
					printf("\nQual vai ser a capacidade da fila? ");
	                scanf("%d",&capa);
	            break;
	            
			default:
				printf("\nOpcao Invalida\n\n");

		}
	}
}