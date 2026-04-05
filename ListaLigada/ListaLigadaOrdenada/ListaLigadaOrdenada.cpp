#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

		NO* atual = primeiro;
		NO* anterior = NULL;
		while (atual != NULL && atual->valor < novo->valor)
		{
			anterior = atual;
			atual = atual->prox;
		}
		
		if (atual != NULL && atual->valor == novo->valor) 
		{
			cout << "Valor ja existe" << endl;
			free(novo);
		}
		else 
		{
			if (anterior == NULL)
			{
				primeiro = novo;
			}
			else
			{
				anterior->prox = novo;
			}
			
			novo->prox = atual;
		}

	}

void excluirElemento()
{
	NO* del = (NO*)malloc(sizeof(NO));

	cout << "Digite o elemento para deletar: ";
	cin >> del->valor;

	NO* atual = primeiro;
	NO* anterior = NULL;
	while (atual != NULL && atual->valor < del->valor)
	{
		anterior = atual;
		atual = atual->prox;

		if (atual->valor > del->valor)
		{
			cout << "Numero nao encontrado" << endl;
			return;
		}
	}
	
	if (anterior == NULL && atual->valor == del->valor) 
	{
		primeiro = atual->prox;
		free(atual);
		return;
	}
	else
	{
		if (atual->valor == del->valor)
		{
			anterior->prox = atual->prox;
			free(atual);
			return;
		}
	}
	cout << "Numero nao encontrado" << endl;

}

void buscarElemento()
{

	NO* aux = primeiro;
	if (aux == NULL)
	{
		cout << "Lista vazia" << endl;
		return;
	}

	int busca;
	cout << "Digite o elemento para procurar: ";
	cin >> busca;
	
	while (aux != NULL)
	{
		if (aux->valor == busca)
		{
			cout << "Valor encontrado" << endl;
			return;
		}
		if (aux->valor > busca)
		{
			cout << "Valor nao encontrado" << endl;
			return;
		}

		aux = aux->prox;
		
	}

	cout << "Valor nao encontrado" << endl;

	}

