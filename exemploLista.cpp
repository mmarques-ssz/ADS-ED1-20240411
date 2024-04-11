#include <iostream>
using namespace std;

struct Lista {
	int dado;
	Lista *prox;
};

Lista* init() {
	return NULL;
}

int isEmpty(Lista* lista) {
	return (lista==NULL);
}


Lista* insert(Lista* lista, int i) {
	Lista* novo = new Lista();
	novo->dado = i;
	novo->prox = lista;
	return novo;
}

void print(Lista* lista) {
	Lista* aux;
	aux = lista;
	while (aux != NULL) {
		cout << "Dado: " << aux->dado << endl;
		aux = aux->prox;
	}
	cout << "---------------" << endl;
}

Lista* find(Lista* lista, int i) {
    Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado != i) {
		aux = aux->prox;
	}	
	return aux;
}

Lista* remove(Lista* lista, int i) {
    Lista* aux;
    Lista* ant = NULL;
    
	aux = lista;
	
	while (aux != NULL && aux->dado != i) {
	    ant = aux;	
		aux = aux->prox;
	}
	
	if (aux == NULL) { // não estava
		return lista;
	}	
	
	if (ant == NULL) { // era o primeiro
		lista = aux->prox;
	}
	else { // estava no meio
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

void freeLista(Lista* lista) {
    Lista* aux;
	aux = lista;
	while (aux != NULL) {
		Lista *ant = aux->prox;
		free(aux);
		aux = ant;
	}	
}

int main(int argc, char** argv)
{
	Lista *minhaLista;
	minhaLista = init();
	
	cout << "Lista vazia: " << 
	     (isEmpty(minhaLista)?"SIM":"NAO") << endl;
	
	minhaLista = insert(minhaLista, 5);
	minhaLista = insert(minhaLista, 10);
	minhaLista = insert(minhaLista, 7);
	
	cout << "Lista vazia: " << 
	     (isEmpty(minhaLista)?"SIM":"NAO") << endl;

	print(minhaLista);
	
	Lista* procurado = find(minhaLista, 10);
	if (procurado != NULL) {
		cout << "Dado encontrado: " << procurado->dado << endl;
	}
	else {
		cout << "Não encontrado" << endl;
	}
	
	minhaLista = remove(minhaLista, 5);
	print(minhaLista);
	
	freeLista(minhaLista);
	
	return 0;
}