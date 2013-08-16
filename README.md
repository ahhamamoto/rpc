# Implementação com RPC

Implementar um agenda eletrônica, com as seguintes funcionalidades: inicializa, insere, consulta, altera e remove.
Utilize uma base de dados de sua preferência, para armazenar os seguintes dados: nome, endereço, telefone.
O campo chave para a busca será o nome.
As funcionalidades devem ser implementadas de forma remota, com o uso de RPC.

A função inicializa deve reiniciar a base(apagar os registros existentes) e carregar os dados de um arquivo contendo
os dados Nome, Endereço e Telefone(nessa sequencia), em linhas separadas. Veja exemplo abaixo:

Ana Maria

Rua Laranjeiras, 123

44 9898 8888

Amadeu da Silva

Av Tororó 34

9879 9087

O arquivo de ser: entrada.txt

Sugestão: implemente de forma centralizada, após confirmar o seu funcionamento, acrescente a distribuição dos procedimentos com RPC.

Relatório contendo resumo sobre RPC, descrição da implementação(o que foi utilizado na implementação, como base, tabelas, etc), 
instruções para compilação e execução do projeto