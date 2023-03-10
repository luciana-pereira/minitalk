# Minitalk
Este projeto consiste na construção de um programa na forma de um _**server**_ e um _**client**_ em C, que se comuniquem através de dois sinais unix **SIGUSR1** e **SIGUSR2** (passando assim os dados em forma binária) enviados com o _**kill()**_, ou seja, envie os dados em binário via sinais unix. Recebendo bits na ordem em que são enviados.

A primeira etapa e fazer a conexão entre os dois programas, então fazemos o _**client**_ enviar um sinal **SIGUSR1** para o  _**server**_ usando o comando _**kill()**_
Com a função _**getpid**_, conseguimos pegar o ID do processo do programa do server para o qual faremos o envio do sinal, que sera reaklizado da seguinte forma:

```
kill(pid, SIGUSR1);
```
A segunda etapa e realizar a conversão de caracters ASCII em binário. A tabela ASCII representa todo os 127 caracters e seus valores, ou seja cada caracter possui um número.

A forma como os programas podem se comunicar atraves dos sinais **SIGUSR1** e **SIGUSR2**, e faze-los representar um valor binario cada, considerando que SIGUSR1 representa 0 e SIGUSR2 representa 1, desta forma quando enviamos o sinal SIGUSR1, estamos enviando o 0 para o servidor, e quando fazemos o mesmo com o SIGUSR2, estamos enviando 1. Nesta etapa obteremos todos os bits de um caracter (8 bits em ASCII), o que significa que o servidor precisara receber os 8 sinais do client para cada caracter ASCII. 

## O que é Unix Signal?
Sinais (signals) é uma interrupção de software** implementadas pelos sistema operaciona que envia uma mensagem simples para um processo "de forma assíncrona" notificando-o de que algo aconteceu (evento).

O processo que recebe o sinal pode executar uma dinâmica básica predeterminada de acordo com o sinal, ignorá-lo por uma função predefinida pelo usuário ou executar um processamento especial.

Por exemplo, um Sinal ocorre quando Ctrl + c é pressionado enquanto um processo está em andamento ou quando um comando kill é emitido para um processo.</br>

💡 **interrupt: Algo que interfere com a execução normal de programas pela CPU**

Portanto, podemos usar o Signal para enviar e receber sinais.

## Eventos POSIX
**SIGUSR1:** De numero 10 e o Sinal 1 definido pelo usuário (POSIX)</br>
**SIGUSR2:** De numero 12 e o Sinal 2 definido pelo usuário (POSIX) 

## Projeto 
**Servidor:** Usando **signal** e **sigaction**, poderemos decidir qual ação tomar quando receber um sinal.</br>
**Cliente:** Podemos enviar um sinal do cliente para o servidor usando a função kill.</br>

Executa uma ação predeterminada ➡️ gera um sinal (função kill, programa cliente) ➡️ o processo. (sinal/sigaction, programa de servidor, funciona de forma assíncrona)

## Funções utilizadas

- <b>signal(): </b>
A função de **_signal_** permite especificar uma função a ser chamada quando um determinado sinal é recebido, para que possa tomar algumas medidas em resposta ao sinal. Se bem-sucedida, executa a função e retorna -1 se falhar.

```
void (*signal(int signum, void (*handler)(int)))(int);
```

- <b>sigemptyset(): </b>
A função sigemptyset é utilizada para inicializar um sinal definido para o conjunto vazio, o que significa que não contém quaisquer sinais. 

```
int sigemptyset(sigset_t *set);
```
<b>Exemplo:</b><br>
Neste exemplo abaixo a <b>sigemptyset</b> é utilizada para inicializar a mascara de sinal, que especifica os sinais que devem ser bloqueados enquanto um manipulador de sinal esta sendo executado.

```
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sig_handler(int signum) {
  printf("Signal recebido %d\n", signum);
 }

int main(void) {
  struct sigaction act;
  act.sa_handler = sig_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGINT, &act, NULL);
  while (1) {
    //código
  }
  return (0);
 }
```

- <b>sigaddset(): </b>
A função sigaddset permite adicionar um sinal a um conjunto de sinais. A função requer dois argumentos: um ponteiro para um conjunto de sinais e o numero do sinal a adicionar ao conjunto.

```
int sigaddset(sigset_t *set, int signum);
```

- <b>sigaction(): </b>
A função sigaction  é utilizado para especificar as medidas a tomar quando um sinal específico é recebido por um processo.

```
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```
Argumentos:
- <b>signum:</b> Especifica o sinal para o qual a ação está a ser especificada.
- <b>act:</b> É um indicador de struct sigaction que especifica a ação a tomar.
- <b>oldact:</b> É um ponteiro para uma struct sigaction que e usada para recuperar a ação anterior para o sinal especifico


## Referências de estudo
Primeiros passos antes de começar a codar, entenda o projeto e o que e solicitado.
- [Entenda como os sinais de interrupção de software](https://blog.pantuza.com/artigos/linux-signals-as-interrupcoes-de-software-na-gestao-de-processos-em-sistemas-operacionais)
- [3.3 Signals por Benjamin Brewster](https://www.youtube.com/watch?v=VwS3dx3uyiQ)
- [Bit Manipulation](https://www.youtube.com/watch?v=7jkIUgLC29I)
- [Manipulação ao nível do bit na linguagem C](https://www.revista-programar.info/artigos/manipulacao-ao-nivel-do-bit-na-linguagem-c/)
- [Codificação de caracteres | Prof. Carlos Maziero](https://wiki.inf.ufpr.br/maziero/doku.php?id=prog2:codificacao_de_caracteres#:~:text=Cada%20caractere%20%C3%A9%20codificado%20em%20um%20byte%2C%20mas,feed%2C%20tab%2C%20etc%29%2C%20que%20dependem%20do%20terminal%20utilizado.)
- [Short introduction to signals in C](https://www.youtube.com/watch?v=5We_HtLlAbs)
- [Signal Sets](https://www.gnu.org/software/libc/manual/html_node/Signal-Sets.html)
- [Minitalk-Main](https://velog.io/@sweetykr/Minitalk-Main)
- [Sigint and other termination signals](https://www.baeldung.com/linux/sigint-and-other-termination-signals)
- [O bit, o byte, o caractere e a palavra - 32 e 64 bits | O Informata #01](https://www.youtube.com/watch?v=NYuZXg2GA9g)
- [Bitwise right shift operator in C](https://www.log2base2.com/C/bitwise/bitwise-right-shift-operator-in-c.html)
- [Conversor | Bitwise Operators](http://www.convertalot.com/bitwise_operators.html)
- [Sending and Handling Signals in C](https://www.youtube.com/watch?v=83M5-NPDeWs)
- [Communicating between processes using signals](https://www.youtube.com/watch?v=PErrlOx3LYE)
- [Enviar sinal para um processo em C](https://www.delftstack.com/pt/howto/c/send-signal-to-process-in-c/)
- [Como enviar e tratar sinais e processos no Linux com C (Parte 1)](https://www.youtube.com/watch?v=CvJYxHrSU88)
- [Como enviar e tratar sinais e processos no Linux com C (Parte 2)](https://www.youtube.com/watch?v=dHXODZrBalY)
- [Automatizar envio de sinais ao processo com um programa de monitoramento](https://www.youtube.com/watch?v=QHLktHXf-Og)
- [Tabela ASCII e código binario](https://marquesfernandes.com/desenvolvimento/codigo-ascii-tabela-ascii-completa/)
- [Sinais no UNIX](http://www.inf.ufes.br/~zegonc/material/Sistemas_Operacionais/Sinais%20no%20UNIX.pdf)
