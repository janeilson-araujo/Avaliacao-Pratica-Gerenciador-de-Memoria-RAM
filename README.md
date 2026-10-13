# INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO CEARÁ

- Curso: Ciência da Computação
- Disciplina: Linguagem de Programação I
- Professor: Evandro de Lima Rodrigues
- Avaliação Prática – Gerenciador de Memória RAM
- Valor: 10,0 pontos
- Aluno(a): __________________________________________________
- Data: _____________________

---

## 1. Contextualização

A memória RAM é um recurso fundamental para a execução de programas. Durante sua execução, um programa pode solicitar blocos de memória para armazenar dados e, posteriormente, liberar esses blocos quando não forem mais necessários.

Na linguagem C, esse gerenciamento pode ser realizado por meio de alocação dinâmica de memória, utilizando funções como `malloc()` ou `calloc()` para alocar memória e `free()` para liberá-la.

Nesta avaliação, você deverá desenvolver um programa que simule o gerenciamento de blocos de memória RAM, permitindo que o usuário realize alocações, libere blocos previamente alocados e consulte o estado da memória simulada.

O sistema deverá utilizar alocação dinâmica real de memória e não apenas apresentar mensagens simulando essas operações. Ressalta-se que o programa não gerenciará diretamente a memória RAM física do computador, mas utilizará os recursos da linguagem C para construir uma simulação didática.

---

## 2. Objetivo

Desenvolver um programa modular em linguagem C que simule o gerenciamento de memória, aplicando os seguintes conceitos:

- Ponteiros;
- Alocação dinâmica de memória;
- Liberação de memória;
- Vetores;
- Constantes;
- Estruturas (`struct`);
- Funções e passagem de parâmetros;
- Modularização por meio de arquivos `.c` e `.h`;
- Validação de entradas e tratamento de erros.

---

## 3. Descrição do problema

Você deverá implementar um sistema denominado Gerenciador de Memória RAM, no qual o usuário poderá alocar blocos de diferentes tamanhos, liberar blocos previamente alocados, consultar o estado dos blocos registrados e visualizar um resumo da memória atualmente ocupada.

O sistema deverá apresentar um menu interativo com as seguintes opções:

### 1 – Alocar bloco de memória

O usuário deverá informar o tamanho do bloco desejado, em bytes. O programa deverá utilizar alocação dinâmica para solicitar a memória, registrar as informações do bloco e apresentar seu identificador, endereço e tamanho.

### 2 – Liberar bloco de memória

O usuário deverá informar o identificador do bloco que deseja liberar. O programa deverá localizar o bloco, verificar se ele está ocupado e utilizar `free()` para liberar a memória correspondente.

Após a liberação, o sistema deverá atualizar o estado do registro para indicar que o bloco está livre. Não será permitido liberar duas vezes o mesmo bloco.

### 3 – Exibir estado da memória

O programa deverá apresentar uma listagem dos blocos registrados, contendo, no mínimo:

- Identificador do bloco;
- Endereço de memória, quando ocupado;
- Tamanho do bloco em bytes;
- Estado do bloco: `LIVRE` ou `OCUPADO`.

Os endereços deverão ser apresentados utilizando o especificador `%p`.

### 4 – Exibir resumo da memória

O sistema deverá apresentar:

- Quantidade total de registros de blocos;
- Quantidade de blocos ocupados;
- Quantidade de blocos livres;
- Total de bytes atualmente alocados.

O total de bytes atualmente alocados deverá considerar somente os blocos que ainda estão ocupados.

### 0 – Encerrar o programa

Antes de encerrar a execução, o programa deverá liberar todos os blocos que ainda estiverem ocupados e desalocar eventuais estruturas auxiliares alocadas dinamicamente.

---

## 4. Requisitos obrigatórios

O programa deverá atender às seguintes regras:

1. Permitir a alocação de blocos com tamanhos variados, informados pelo usuário em bytes.
2. Rejeitar solicitações de alocação com tamanho igual a zero ou inválido.
3. Verificar se a alocação dinâmica foi realizada com sucesso.
4. Atribuir um identificador único a cada bloco durante a execução do programa.
5. Impedir a liberação duplicada de um mesmo bloco.
6. Informar quando o identificador de um bloco não existir.
7. Manter informações suficientes para consultar o estado dos blocos, inclusive daqueles que já foram liberados.
8. Utilizar ponteiros para armazenar e manipular os endereços retornados pela alocação dinâmica.
9. Utilizar estruturas (`struct`) para representar os blocos de memória.
10. Utilizar vetores para armazenar os registros dos blocos.
11. Organizar o código em funções, respeitando a separação de responsabilidades entre os arquivos.
12. Garantir que toda a memória dinâmica alocada pelo programa seja liberada antes do encerramento.

---

## 5. Organização obrigatória do projeto

O projeto deverá ser dividido em três arquivos:

### 5.1. Arquivo `main.c`

Responsável pelo programa principal e pela interação com o usuário.

Deverá:

- Apresentar o menu de opções;
- Ler e validar as opções selecionadas;
- Solicitar os dados necessários para as operações;
- Chamar as funções implementadas no módulo de memória;
- Controlar a repetição do menu;
- Garantir a liberação dos recursos antes de encerrar o programa.

### 5.2. Arquivo `memoria.h`

Responsável pelas declarações compartilhadas entre os módulos.

Deverá conter:

- As constantes necessárias ao funcionamento do sistema;
- A definição da estrutura utilizada para representar os blocos de memória;
- Os protótipos das funções implementadas em `memoria.c`;
- As diretivas de proteção contra inclusões múltiplas, utilizando `#ifndef`, `#define` e `#endif`.

### 5.3. Arquivo `memoria.c`

Responsável pela implementação das funcionalidades relacionadas ao gerenciamento da memória.

Deverá conter as funções responsáveis por:

- Inicializar o gerenciador de memória;
- Alocar blocos de memória;
- Liberar blocos previamente alocados;
- Exibir o estado dos blocos;
- Apresentar o resumo da memória;
- Liberar todos os blocos e recursos auxiliares antes do encerramento.

As funções de gerenciamento deverão ser implementadas em `memoria.c`. O arquivo `main.c` deverá utilizar essas funções por meio dos protótipos declarados em `memoria.h`.

---

## 6. Modelagem dos dados

Você deverá definir uma estrutura para representar cada bloco de memória.

A estrutura deverá armazenar informações que permitam identificar o bloco, conhecer seu endereço, registrar seu tamanho e verificar se ele está livre ou ocupado.

Uma possibilidade de modelagem é:

```c
typedef struct {
    int id;
    void *endereco;
    size_t tamanho;
    int ocupado;
} BlocoMemoria;
```

A estrutura apresentada é apenas uma sugestão. Você deverá compreender a finalidade de cada campo e utilizá-lo corretamente na implementação.

O vetor de registros deverá permitir consultar os blocos que ainda estão ocupados e aqueles cuja memória já foi liberada.

> Importante: o registro do bloco e a memória apontada por ele são elementos distintos. A liberação da memória não exige, necessariamente, a remoção do registro do vetor. O sistema deverá manter uma representação consistente do estado de cada bloco.

---

## 7. Exemplo de funcionamento

O exemplo a seguir apresenta uma execução ilustrativa do sistema. Os endereços são fictícios e servem apenas para demonstrar o formato esperado da saída.

```text
========== GERENCIADOR DE MEMÓRIA ==========
1 - Alocar bloco de memória
2 - Liberar bloco de memória
3 - Exibir estado da memória
4 - Exibir resumo da memória
0 - Encerrar

Escolha uma opção: 1
Informe o tamanho do bloco em bytes: 128
Bloco alocado com sucesso!
Identificador: 1
Endereço: 0x1000
Tamanho: 128 bytes
Estado: OCUPADO

Escolha uma opção: 1
Informe o tamanho do bloco em bytes: 256
Bloco alocado com sucesso!
Identificador: 2
Endereço: 0x2000
Tamanho: 256 bytes
Estado: OCUPADO

Escolha uma opção: 2
Informe o identificador do bloco: 1
Bloco 1 liberado com sucesso.

Escolha uma opção: 3
ID ENDEREÇO TAMANHO ESTADO
1 (liberado) 128 bytes LIVRE

2 0x2000 256 bytes OCUPADO

Escolha uma opção: 4
Total de registros: 2
Blocos ocupados: 1
Blocos livres: 1
Bytes atualmente alocados: 256

Escolha uma opção: 0
Liberando blocos restantes...
Todos os recursos foram liberados.
Programa encerrado.
```

---

## 8. Casos de teste

A solução deverá ser testada, no mínimo, nas seguintes situações:

- Teste 1 – Alocação de tamanhos diferentes: alocar três blocos de 64, 128 e 512 bytes e verificar seus identificadores, endereços e tamanhos.
- Teste 2 – Liberação de bloco: liberar um bloco ocupado e verificar se seu estado passa a ser `LIVRE`.
- Teste 3 – Tentativa de dupla liberação: tentar liberar novamente um bloco já liberado e verificar se o sistema rejeita a operação.
- Teste 4 – Identificador inexistente: tentar liberar um bloco com identificador que não esteja registrado.
- Teste 5 – Tamanho inválido: tentar alocar um bloco com tamanho zero ou informar um valor inválido.
- Teste 6 – Encerramento do programa: alocar vários blocos e encerrar o sistema sem liberar individualmente todos eles. O programa deverá liberar automaticamente os blocos restantes.

---

## 9. Critérios de avaliação

A avaliação valerá 10,0 pontos, distribuídos da seguinte forma:

| Critério | Pontuação |
|---|---:|
| Organização e modularização correta em `main.c`, `memoria.c` e `memoria.h` | 1,5 |
| Definição e utilização adequada de estruturas, ponteiros, vetores e constantes | 1,5 |
| Implementação da alocação dinâmica, incluindo validações e tratamento de falhas | 2,0 |
| Implementação da liberação dos blocos, evitando dupla liberação e erros de gerenciamento | 1,5 |
| Exibição correta do estado dos blocos e do resumo da memória | 1,5 |
| Liberação de todos os recursos dinâmicos ao encerrar o programa | 1,0 |
| Validação das entradas, tratamento de situações inválidas e clareza das mensagens | 1,0 |
| **TOTAL** | **10,0** |

A pontuação será atribuída de acordo com o funcionamento efetivo do programa, a organização do código e a correta aplicação dos conceitos estudados.

---

## 10. Entrega da avaliação

O projeto deverá ser organizado da seguinte maneira:

```text
gerenciador_memoria/
├── main.c
├── memoria.c
└── memoria.h
```

Boa avaliação!
