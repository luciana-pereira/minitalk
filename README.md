# Minitalk
Este projeto consiste na construção de um programa na forma de um servidor e um client em C, que se comuniquem através de dois sinais unix SIGUSR1 e SIGUSR2 (passando assim os dados em forma binária) enviados com o kill, ou seja, envie os dados em binário via sinais unix. Recebendo bits na ordem em que são enviados.

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
Executa a função do handler se bem-sucedida e retorna -1 se falhar.

```
void (*signal(int signum, void (*handler)(int)))(int);
```

- <b>sigemptyset(): </b>
A função sigemptyset é utilizada para inicializar um sinal definido para o conjunto vazio, o que significa que não contém quaisquer sinais. 

```
int sigemptyset(sigset_t *set);
```

## Referências de estudo
Primeiros passos antes de começar a codar, entenda o projeto e o que e solicitado.
- [Entenda como os sinais de interrupção de software](https://blog.pantuza.com/artigos/linux-signals-as-interrupcoes-de-software-na-gestao-de-processos-em-sistemas-operacionais)
- [3.3 Signals por Benjamin Brewster](https://www.youtube.com/watch?v=VwS3dx3uyiQ)
- [Bit Manipulation](https://www.youtube.com/watch?v=7jkIUgLC29I)
- [Short introduction to signals in C](https://www.youtube.com/watch?v=5We_HtLlAbs)
- [Signal Sets](https://www.gnu.org/software/libc/manual/html_node/Signal-Sets.html)
- [Minitalk-Main](https://velog.io/@sweetykr/Minitalk-Main)
- [Sigint and other termination signals](https://www.baeldung.com/linux/sigint-and-other-termination-signals)
