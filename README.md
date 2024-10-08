# Sistema de Supermercado em C - README

## Descrição do Projeto

Este projeto é um sistema simples de gerenciamento de supermercado desenvolvido em linguagem C. O sistema permite o cadastro de produtos, listagem de produtos, adição de produtos ao carrinho de compras, visualização e remoção de itens do carrinho, e finalização do pedido com cálculo do valor total da compra. O objetivo é demonstrar o uso de estruturas de dados (`structs`), arrays e funções em um programa modular.

## Funcionalidades do Sistema

### 1. Cadastrar Produto
- O usuário pode cadastrar novos produtos com um código único, nome e preço.
- Antes do cadastro, o sistema exibe a lista de produtos já cadastrados. Caso não existam produtos, é exibida uma mensagem "Nenhum produto cadastrado, cadastre seu primeiro produto".

### 2. Listar Produtos
- Exibe todos os produtos cadastrados no sistema, mostrando o código, nome e preço (com o símbolo `$`).
- Permite ao usuário verificar os produtos disponíveis para compra.

### 3. Comprar Produto
- Lista os produtos disponíveis para que o usuário saiba quais estão disponíveis para compra.
- Permite ao usuário selecionar um produto pelo seu código e adicionar uma quantidade específica ao carrinho.
- Se o produto já estiver no carrinho, a quantidade é atualizada em vez de duplicar o item.

### 4. Visualizar Carrinho
- Exibe todos os produtos atualmente no carrinho, mostrando o código, nome, quantidade, preço unitário e subtotal.

### 5. Remover Produto do Carrinho
- Lista os produtos no carrinho para facilitar a escolha do usuário.
- O usuário pode especificar o código do produto a ser removido e a quantidade que deseja remover.
- A quantidade a ser removida não pode exceder a quantidade disponível no carrinho.
- Se a quantidade do produto no carrinho se tornar zero, o produto é removido completamente do carrinho.

### 6. Fechar Pedido
- Calcula o valor total da compra e exibe uma fatura detalhada com os produtos, suas quantidades e subtotais.
- Limpa o carrinho após a finalização do pedido.

### 7. Sair
- Encerra o programa com uma mensagem de agradecimento.

## Estrutura de Dados

- **`Produto`**: Estrutura que armazena os dados do produto:
  - `int codigo`: Código único do produto.
  - `char nome[30]`: Nome do produto.
  - `float preco`: Preço do produto.

- **`Carrinho`**: Estrutura que armazena os produtos adicionados ao carrinho e a quantidade de cada um:
  - `Produto produto`: Produto selecionado.
  - `int quantidade`: Quantidade do produto no carrinho.

## Como o Sistema Foi Desenvolvido

O sistema foi desenvolvido em C, utilizando estruturas (`structs`) para representar os produtos e os itens no carrinho. Arrays estáticos são usados para armazenar até 50 produtos e até 50 itens no carrinho.

Funções foram criadas para modularizar as operações principais do sistema:
- `menu()`: Gerencia o fluxo do programa e as opções do usuário.
- `cadastrarProduto()`: Permite o cadastro de novos produtos, listando os produtos existentes previamente.
- `listarProdutos()`: Exibe todos os produtos cadastrados.
- `comprarProduto()`: Lista os produtos disponíveis e permite ao usuário adicionar produtos ao carrinho.
- `visualizarCarrinho()`: Exibe os produtos atualmente no carrinho.
- `removerProduto()`: Permite a remoção de produtos do carrinho, verificando a quantidade a ser removida.
- `fecharPedido()`: Calcula e exibe o valor total da compra, limpa o carrinho e exibe a fatura.
- `temNoCarrinho()`: Verifica se um produto já está no carrinho.
- `pegarProdutoPorCodigo()`: Retorna um produto a partir do código informado.
- `infoProduto()`: Exibe as informações de um produto, incluindo o preço com símbolo `$`.

## Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado.
- Um terminal ou prompt de comando.

### Passo a Passo para Compilar
1. Salve o código em um arquivo chamado `supermercado.c`.
2. Abra o terminal e navegue até o diretório onde o arquivo `supermercado.c` está salvo.
3. Use o seguinte comando para compilar o programa:
   ```bash
   gcc supermercado.c -o supermercado
