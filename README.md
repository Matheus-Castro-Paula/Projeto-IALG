# Relatório do Projeto Prático: Sistema de Gestão dos 100 Melhores Clubes de Futebol Atualmente

**Universidade Federal de Lavras - UFLA**
**Departamento de Ciência da Computação**
**Disciplina:** Introdução aos Algoritmos 

---

## Membros da Equipe e Contribuições

* **Carolina Carvalho Maurício Silva** (Matrícula: 202520209)
    * Responsável pelas funções de persistência de dados (`salvarBinario` e escrita do novo CSV).
    * Implementação da lógica de inserção de dados (`inserirElemento`).
    * Desenvolvimento da função de ordenação e impressão dos resultados (`ordenar_e_imprimir_elementos`).

* **Kauã Augusto Canaan Nascimento** (Matrícula: 202520211)
    * Estruturação principal do programa (`int main`) e definição da `struct`.
    * Implementação da leitura inicial do arquivo (`lerRegistros`).
    * Configuração de portabilidade e acentuação (`acentuacao`).
    * Desenvolvimento de funções utilitárias (`limparBuffer`).

* **Matheus de Castro Paula** (Matrícula: 202520203)
    * Implementação dos algoritmos de manipulação complexa (`excluirElemento` e `buscarElemento`).
    * Desenvolvimento das funções de ordenação (*Selection Sort*).
    * Implementação das funções de busca binária recursiva.

**Tema:** 100 Melhores Clubes de Futebol Atualmente

---

## 1. Introdução

O presente trabalho consiste na implementação de um sistema de cadastro e gerenciamento de dados em arquivos, desenvolvido na linguagem C++. O software tem como objetivo manipular registros de Clubes de Futebol, permitindo operações de inserção, remoção (unitária e sequencial), busca (binária e sequencial), ordenação e persistência de dados em arquivos CSV e Binários.

O projeto foi desenvolvido seguindo estritamente as diretrizes da disciplina, priorizando a implementação manual de algoritmos e estruturas de dados (como alocação dinâmica e métodos de ordenação), visando demonstrar domínio sobre o gerenciamento de memória e lógica algorítmica.

---

## 2. Estruturas e Lógica do Sistema

O sistema foi estruturado de maneira modular, com funções específicas para cada operação (Leitura, Escrita, Busca, Ordenação, Inserção e Exclusão).

### 2.1. Definição do Registro
Para representar os dados em memória RAM, foi utilizada uma `struct` chamada `Clube`, contendo os seguintes campos:
* **id (int):** Identificador numérico sequencial.
* **nome (string):** Nome do clube.
* **pais (string):** País de origem.
* **anoFundacao (short):** Ano de fundação do clube.
* **descricao (string):** Breve descrição textual do clube.

* **Lembrando que todas as strings podem ter espaços**

### 2.2. Alocação Dinâmica e Gerenciamento de Memória
O sistema opera inteiramente com vetores alocados dinamicamente (`new` e `delete`).
* **Carregamento:** O vetor inicial é criado com o tamanho exato lido do arquivo de entrada.
* **Redimensionamento:** Para operações de inserção e exclusão, a estratégia adotada foi a criação de um novo vetor auxiliar com o novo tamanho necessário. Os dados são copiados ou filtrados do vetor antigo para o novo, a memória antiga é liberada e o ponteiro principal é atualizado para apontar para o novo bloco de memória.

### 2.3. Algoritmos de Ordenação
Foi implementado o algoritmo **Selection Sort** (Ordenação por Seleção). Foram criadas quatro variações da função para permitir a ordenação por qualquer um dos critérios (ID, Nome, País ou Ano). O método foi escolhido por ser estável e de fácil entendimento e utilização.

### 2.4. Algoritmos de Busca
* **Busca Binária (Recursiva):** Implementada para localizar registros específicos por ID, Nome, País ou Ano. O sistema garante a eficiência da busca ordenando previamente o vetor pelo critério escolhido antes de executar a busca binária.
* **Busca Sequencial:** Utilizada para operações de intervalo (ex: excluir do registro X ao Y) e listagem de trechos.

---

## 3. Organização dos Dados no Arquivo

O sistema lê um arquivo inicial (`Banco de Dados.csv`) e gera dois arquivos de saída ao final (`New Banco de Dados.csv` e `Banco de dados.bin`).

### Estrutura do CSV:
1.  **Cabeçalho (Linha 1):** Títulos das colunas (ignorados na leitura).
2.  **Contador (Linha 2):** Um número inteiro indicando a quantidade total de registros.
3.  **Registros (Linhas subsequentes):** Seguem o padrão:
    `ID, Nome, País, Ano, "Descrição"`

Exemplo:
```csv
identificador,nome...
3
1, Flamengo, Brasil, 1895, "Clube popular"
2, Real Madrid, Espanha, 1902, "Maior da Europa"
3, Boca Juniors, Argentina, 1905, "Tradicional"
```
A descrição é armazenada entre aspas duplas para preservar a formatação e permitir caracteres especiais.

---

## 4. Análise do Desenvolvimento

### 4.1. Acertos
* **Robustez na Entrada de Dados:** A implementação da função `limparBuffer()` (utilizando `numeric_limits`) foi crucial para evitar erros de "pulo" de leitura (`getline`) após a entrada de números inteiros, um problema comum em C++.
* **Portabilidade:** O uso de diretivas de pré-processamento (`#ifdef _WIN32`) garantiu que a acentuação funcionasse corretamente tanto em terminais Windows quanto Linux.
* **Lógica de Exclusão:** A separação da lógica de exclusão física (cópia para novo vetor) da lógica de reordenação de IDs evitou inconsistências nos índices.

### 4.2. Dificuldades Encontradas
* **Reindexação de IDs:** Durante o desenvolvimento, observou-se que excluir registros ordenados por nome causava a perda da sequencialidade dos IDs (ex: IDs ficavam 1, 5, 2...). A solução foi ordenar o vetor final por ID antigo antes de aplicar a renumeração sequencial (1, 2, 3...).
* **Manipulação de Buffer:** Entender o comportamento do `cin >>` versus `getline` exigiu testes exaustivos para determinar onde exatamente o buffer de entrada precisava ser limpo.
* **Menus no Terminal:** Como o código foi todo criado em Windows, o tamanho do terminal era diferente do terminal do Linux, então foram necessários vários testes nas maquinas da UFLA para a parte visual ser executada com êxito.

---

## 5. Conclusão

O projeto cumpriu todos os requisitos propostos. O sistema final é capaz de gerenciar uma base de dados completa, realizando operações CRUD com segurança de memória. A implementação manual dos algoritmos de ordenação e busca permitiu uma compreensão profunda sobre complexidade e manipulação de ponteiros em C++. O resultado é uma aplicação funcional, portátil e organizada.

---

## Como Compilar e Rodar

Para compilar o projeto via terminal (Linux ou Windows com MinGW):

```bash
g++ main.cpp -o gerenciador_clubes
./gerenciador_clubes
```

Certifique-se de que o arquivo `Banco de Dados.csv` esteja na mesma pasta do executável e com o nome correto.