# 🕹️ Mundo dos Jogos em C

Projeto prático desenvolvido em C que reúne dois jogos clássicos em um único menu. O objetivo foi treinar lógica de programação, manipulação de textos e controle de fluxo.

---

## 👨‍💻 Identificação
- **Nome:** Mariana Santa Rosa Vieira                                                                   
- **Matrícula:** 252027007

---

## 📝 Sobre o Projeto
É um sistema simples que roda no terminal. Ao iniciar, o usuário digita o nome e escolhe entre duas opções de diversão. O código trata erros de digitação (buffer do teclado) e limpa a tela para deixar a interface organizada.

### Os Jogos:
1.  **💀 Jogo da Forca:**
    * O programa sorteia uma palavra aleatória de uma lista.
    * Você tem 5 vidas para acertar as letras.
    * Mostra as letras que você já tentou e preenche a palavra conforme você acerta.
    
2.  **🔢 Adivinhe o Número:**
    * O computador "pensa" em um número de 1 a 100.
    * Você escolhe a dificuldade (Fácil, Médio ou Difícil), que define quantas vidas você tem.
    * O jogo avisa se o número secreto é maior ou menor que o seu chute.

---

## 📚 O que foi aprendido
Para fazer isso funcionar, utilizei:
* **Funções:** Separei cada jogo em uma função própria (`forca` e `adivinha`) para organizar o código.
* **Strings:** Manipulação de nomes e palavras usando vetores de char.
* **Tratamento de Buffer:** Aprendi a usar `getchar()` para evitar que o "Enter" pule jogadas no `scanf`.
* **Lógica:** Loops (`while`, `for`) e condicionais (`if/else`) para controlar vidas e vitórias.

---

## 🚀 Como Rodar
Se você tiver um compilador C instalado (como o GCC), basta abrir o terminal na pasta do arquivo e digitar:

1. **Compilar:**
   bash
   gcc main.c -o meusjogos
