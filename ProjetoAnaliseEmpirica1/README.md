# Análise Empírica

Projeto da disciplina de EDB I, ministrada pelo professor Selan Rodrigues.

## Descrição

O projeto tem o intuito de analisar o tempo de execução de sete algoritmos de busca em vetores ordenados.
São esses algoritmos : Linear Search, Binary Search Iterative e Recursive, Ternary Search Iterative e Recursive, Jump Search e Fibonacci Search.

### Execução

Para gerar o executavel do programa rode:

```
Make
```
Para salvar os dados em um arquivo .csv:

```
./executavel <in.data> "arquivo.csv"
```
Para apagar o executável:

```
make clean
```

## Arquivos do projeto

A seguir descreveremos os arquivos que estão no projeto.

### main.cpp

Responsável por gerar os resultados e calcular o tempo de execução

### search.inl

Guarda todas as funções de todos os algoritmos de busca.

### search.h

Armazena as assinaturas das funções