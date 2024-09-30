#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 50
#define MAX_CARRINHO 50

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

Produto produtos[MAX_PRODUTOS];
Carrinho carrinho[MAX_CARRINHO];
int numProdutos = 0;
int numCarrinho = 0;

void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
void removerProduto();
int temNoCarrinho(int codigo);
Produto* pegarProdutoPorCodigo(int codigo);
void infoProduto(Produto prod);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;

    do {
        printf("\n--- Sistema de Supermercado ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Visualizar Carrinho\n");
        printf("5. Remover Produto do Carrinho\n");
        printf("6. Fechar Pedido\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                cadastrarProduto(); 
                break;
            case 2: 
                listarProdutos(); 
                break;
            case 3: 
                comprarProduto(); 
                break;
            case 4: 
                visualizarCarrinho(); 
                break;
            case 5: 
                removerProduto(); 
                break;
            case 6: 
                fecharPedido(); 
                break;
            case 7: 
                printf("Obrigado por comprar na nossa loja!\n"); 
                break;
            default: 
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);
}

void cadastrarProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos cadastrados atingido.\n");
        return;
    }

    if (numProdutos > 0) {
        listarProdutos();
    } else {
        printf("Nenhum produto cadastrado, cadastre seu primeiro produto.\n");
    }

    Produto novoProduto;
    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]%*c", novoProduto.nome); 
    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    produtos[numProdutos] = novoProduto;
    numProdutos++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < numProdutos; i++) {
        infoProduto(produtos[i]);
    }
}

void infoProduto(Produto prod) {
    printf("Codigo: %d, Nome: %s, Preco: $%.2f\n", prod.codigo, prod.nome, prod.preco);
}

void comprarProduto() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    listarProdutos();

    int codigo, quantidade;
    printf("Digite o codigo do produto para adicionar ao carrinho: ");
    scanf("%d", &codigo);

    Produto* prod = pegarProdutoPorCodigo(codigo);
    if (prod == NULL) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    int indiceCarrinho = temNoCarrinho(codigo);
    if (indiceCarrinho != -1) {
        carrinho[indiceCarrinho].quantidade += quantidade;
    } else {
        if (numCarrinho >= MAX_CARRINHO) {
            printf("Carrinho cheio.\n");
            return;
        }
        carrinho[numCarrinho].produto = *prod;
        carrinho[numCarrinho].quantidade = quantidade;
        numCarrinho++;
    }

    printf("Produto adicionado ao carrinho!\n");
}

void visualizarCarrinho() {
    if (numCarrinho == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }

    printf("\n--- Produtos no Carrinho ---\n");
    for (int i = 0; i < numCarrinho; i++) {
        printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco Unitario: $%.2f, Subtotal: $%.2f\n",
               carrinho[i].produto.codigo, carrinho[i].produto.nome, carrinho[i].quantidade,
               carrinho[i].produto.preco, carrinho[i].produto.preco * carrinho[i].quantidade);
    }
}

void fecharPedido() {
    if (numCarrinho == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }

    float total = 0.0;

    printf("\n--- Fatura ---\n");
    for (int i = 0; i < numCarrinho; i++) {
        float subtotal = carrinho[i].produto.preco * carrinho[i].quantidade;
        printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco Unitario: $%.2f, Subtotal: $%.2f\n",
               carrinho[i].produto.codigo, carrinho[i].produto.nome, carrinho[i].quantidade,
               carrinho[i].produto.preco, subtotal);
        total += subtotal;
    }

    printf("Total da compra: $%.2f\n", total);
    numCarrinho = 0;
    printf("Pedido fechado com sucesso!\n");
}

void removerProduto() {
    if (numCarrinho == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }

    visualizarCarrinho();

    int codigo, quantidade;
    printf("Digite o codigo do produto a ser removido do carrinho: ");
    scanf("%d", &codigo);

    int indice = temNoCarrinho(codigo);
    if (indice == -1) {
        printf("Produto nao encontrado no carrinho.\n");
        return;
    }

    printf("Digite a quantidade a ser removida: ");
    scanf("%d", &quantidade);

    if (quantidade > carrinho[indice].quantidade) {
        printf("Quantidade invalida! Voce so pode remover ate %d unidade(s).\n", carrinho[indice].quantidade);
        return;
    }

    carrinho[indice].quantidade -= quantidade;

    if (carrinho[indice].quantidade == 0) {
        for (int i = indice; i < numCarrinho - 1; i++) {
            carrinho[i] = carrinho[i + 1];
        }
        numCarrinho--;
    }

    printf("Produto removido do carrinho com sucesso!\n");
}

int temNoCarrinho(int codigo) {
    for (int i = 0; i < numCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            return i;
        }
    }
    return -1;
}

Produto* pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return &produtos[i];
        }
    }
    return NULL;
}
