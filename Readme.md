# Sistema de Gestão de Faturamento de Telecomunicação

## Descrição 

Esse projeto simula um sistema simples de Faturamento de Telecomunicação desenvolvido na linguagem C. Ele permite o usuário realizar cadastros, modificações, pagamentos, buscas e gerenciamento das faturas dos clientes cadastrados por meio de um Menu desenvolvido em C.

## Funcionalidades
- Login de Usuario : Validação de credenciais para acesso ao sistema.
- Adicionar novo Registro de Fatura : Cadastro de cliente incluindo número de telefone, nome e valor da fatura.  
- Exibir Registros de Contas : Listar todos as faturas registradas no sistema.
- Modificar Registro de Fatura : Alterar informações do cliente caso seu número de telefone esteja cadastrado.
- Gerenciar Transação de Pagamento : Realiza os pagamentos das faturas dos clientes.
- Buscar Registro de Fatura do Cliente : Localiza informações de um cliente por número de telefone.
- Login de Usuário : Valida o usuario para acessar o programa.

## Estrutura do Código

Esse programa utilizar struct para armazenar os dados dos clients (número de telefone, nome e valor da fatura)

Funções Principais:

- Funções para exibição de cabeçalho e menu interativo
- Função para validação de login
- Funções para operações de gerenciamento, como adicionar, exibir, modificar, buscar e processar pagamentos de registros.

## Como Usar
1. Compile o código:
   ```
   gcc main.c -o main
   ```
2. Execute o programa:
   ```
   ./main
   ```

3. Login inicial:

Usuário: ADM
Senha: 12345

## Créditos
A ideia desse projeto foi retirado no conteúdo disponível em: [Link do Site](https://www.sourcecodester.com/cc/17000/telecom-billing-management-system-c-source-code.html).