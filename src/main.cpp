#include <Arduino.h>
#include <string.h> //* strlen. strcpy. strcat. strcmp. strchr
#include <stdlib.h> //* atoi

void textoTipoString();
void textoTipoC();

void setup()
{

  Serial.begin(9600);
  Serial.println();
  textoTipoC();
  textoTipoString();
}

void loop()
{
}

void textoTipoC()
{
  //* Texto literal
  //* Use const char* quando o texto nao sera alterado

  const char *cidade = "Sao Paulo Capital";
  const char outraCidade[] = "Sao Caetano";
  Serial.println(cidade);
  Serial.println(outraCidade);

  //* Descobrindo o tamanho do texto
  //* strlen conta quantos caracteres antes do '\O'
  int tamanhoCidade = strlen(cidade);
  int tamanhoOutraCidade = strlen(outraCidade);

  Serial.print("Comprimento do texto em caracteres: ");
  Serial.println(tamanhoOutraCidade);

  Serial.print("Tamanho do conteudo do ponteiro: ");
  Serial.println(tamanhoCidade);

  //* Descobrindo o tamanho ocupado

  int tamanhoVariavel = sizeof(outraCidade);
  int tamanhoPonteiro = sizeof(cidade);

  //*Quando usando o sizeof em uma string sempre retornara
  //* um byte a mais que a quantidade de caracteres por
  //* conta do '\0' que finaliza o texto
  Serial.print("Tamanho da variavel em bytes: ");
  Serial.println(tamanhoVariavel);

  //* Quando usamos o sizeof em ponteiros retorna sempre em 4bytes
  //* pois o conteudo dele e um endereco de memoria como 0xFF00C245
  Serial.print("Tamanho do ponteiro: ");
  Serial.println(tamanhoPonteiro);

  //* O caractere '\0' eh colocado automaticamente quando escrevemos
  //* um texto entre aspas duplas " ".
  const char vetorTexto[8] = {'G', 'i', 's', 'e', 'l', 'l', 'y', '\0'};
  Serial.println(vetorTexto);

  //* Comparar texto
  const char *cidade1 = "Porto Alegre";
  const char *cidade2 = "Porto Alegre";

  if (strcmp(cidade1, cidade2) == 0)
    Serial.println("As strings sao iguais");
  else
    Serial.println("As strings sao diferentes");

  //* strcmp analize a ordem lexica (ordem alfabetica) das palavras, se a primeira palavra vem antes,
  //* o valor retornado sera menor que zero, se a primeira vem apos a segunda, o retorno sera maior que zero.

  //*==========================
  //* TEXTO EDITAVEL COM char()
  //*==========================

  char nomeAluno[8] = "Joao";
  Serial.println(nomeAluno);

  nomeAluno[4] = 'o';
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor
  //! Cuidado o vetor precisa ter espaco suficiente

  strcpy(nomeAluno, "Tadeu");
  Serial.println(nomeAluno);

  //*Concatenando(juntando) texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo cruel!");
  Serial.println(frase);

  //*Procurando um caractere no texto

  char *posicaoLetra = strchr(frase, 'M');

  if (posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada");
    Serial.println(posicaoLetra);
  }
  else
    Serial.println("Letra nao encontrada");

  //* Convertendo texto numerico para inteiro
  char idadeTexto[] = "39"; //* [0x33, 0x57, 0x00]
  int idade = atoi(idadeTexto);

  //* Montando textos
  char buffer[100];
  char *local = "Sala de aula";
  float temperatura = 26.4;
  int umidade = 72;

  snprintf(buffer, sizeof(buffer), "%s | Temp: %f c | Umid: %d %% \n \r", local, temperatura, umidade);

  Serial.print(buffer);

  //* snprintf monta o texto dentro de um vetor de char
  //* isso e muito util quando depois voce quer :
  //* -- enviar em MOTT
  //* -- salvar em variavel
  //* -- Mudar para o display
  //* -- Imprimir na serial
  //*
  //* ESPECIFICADORES
  //*
  //*    %d ou %i      -int
  //*    %u            -unsigned int
  //*    %ld           -long
  //*    %lu           -unsigned long
  //*    %f            -float
  //*    %e            -notacao cientifica
  //*    %g            -float, formato mais curto
  //*    %c            -char
  //*    %s            -char*
  //*    %x ou %X      -haxadecimal minuscula/maiusculo
  //*    %o            -octal
  //*    %p            -ponteiro
  //*    %%            - o proprio %
  //*
  //* FLAGS, largura e precisao
  //*
  //*    %5d        -imprime com largura minima de 5, alinhado a direita [    3] [  100] [100000]
  //*    %-2d       -imprime com largura minima de 2, alinhando a esquerda
  //*    %04d       -completa com zeros ex. 0022
  //*    %+d        -sempre mostra o sinal ex. +5
  //*    %.2f       -2 casas decimais
  //*    %4.2f      -largura de 4 com 2 casas
  //*    %02X       -hexadecimal com 2 digitos
  //*    %#X        -prefixo 0x
  //*    %.3s       -so os primeiros 3 caracteres da string
  //*    %+d        -largura passada como argumento ex. snprintf (buffer, sizeof(buffer), "%+d", 5, 42) [  42]

  void textoTipoString()
  {
    String nome = "Joao";
    String curso = "Lógica de programação";
    String mensagem = "Ola";

    mensagem = mensagem = ", " + "! Bem vindo ao curso de " + curso + ".";

    Serial.println(mensagem);

    //* tamanho da string
    int tamanhoMensagem = mensagem.length();
    Serial.printf("tamanho da string em letra: %u");

    //* Acessando um caractere em uma posicão especifica
    char primeiraLetra = mensagem.charAt(0);
    Serial.printf("Primeira letra: %c\n\r", primeiraletra);

    //* Tambem é possivel acessar com colchetes
    char ultimaLetra = mensagem[tamanhoMensagem];
    Serial.printf("Ultima letra: %c\n\r", ultimaLetra);

    //* Procurando um texto dentro da String
    int posicaoTextoProcurado = mensagem.indexOf("curso");
    Serial.printf("A palavra procurada está na posicão: %d\n\r", posicaoTextoProcurado);

    int inicioNomeCurso = posicaoTextoProcurado + 9; //* posicao da palacra curso + 9 posicoes a frente

    String nomeDoCursoTexto = mensagem.subtring(inicioNomeCurso, tamanhoMensagem - 1);
    Serial.printf("Nome do curso: %s\n\r", nomeDoCursoTexto.c_str());

    //* substituindo um trecho dentro da String
    mensagem.replace("olá,", "Boa Tarde! ");
    Serial.println(mensagem);

    //* Convertendo tudo em maisculas
    mensagem.toUpperCase();
    Serial.println(mensagem);

    //* convertendo tudo em minusculas
    mensagem.toLowerCase();
    Serial.println(mensagem);

    //* Verificando se uma String está vazia
    String textoVazio = "";
    if(textoVazio.length() == 0) Serial.println("O texto está vazio");

    //* Convertendo texto númerico para inteiro
    String textoNumero = "725";
    int numero = textoNumero.toInt();
    Serial.print(numero / 5);

    //* Convertendo String para const char* (texto tipo c)
    const char* textoComoChar = mensagem.c_str();
    Serial.println(textoComoChar);
  }
}

