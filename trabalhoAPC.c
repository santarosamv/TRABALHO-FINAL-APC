#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


void adivinha(char * nome){
    printf("                                              ☆☆ ADIVINHE O NÚMERO ☆☆ \n\n\n");
    
    //String que representa a quantidade de vidas e o nível do jogo
    int vidas;
    int dificuldade;
    
    printf("                                                 Escolha a sua dificuldade\n");
    printf("                                                   1- Facil\n");
    printf("                                                   2- Media\n");
    printf("                                                   3- Dificil\n");
    
    scanf("%d", &dificuldade);
    getchar();
    system("clear");
    
    //Número de tentativasque o jogador tem de acordo com o nível escolhido
    if(dificuldade == 1) vidas = 10;
    else if(dificuldade == 2) vidas = 5;
    else vidas = 3;
    
        
        printf("                                     Um número entre 1 e 100 foi escolhido. Consegue adivinhar qual é?\n");
        
        //Escolha de um número aleatório entre 1 e 100
        int numero = (rand() % 100) +1;
        
        //String que representa o número escolhido pelo jogador
        int chute = 0;
        
        //Loop que durará enquanto o jogador não tiver acertado e ainda tiver vidas
        while (chute != numero && vidas) {
            
            printf("Vidas restantes: %d\n", vidas);
            printf("\n                                     %s, digite o seu chute: ", nome);
            scanf("%d", &chute);
             system("clear");
            
            //Se o número chutado for menor que o correto, será recomendado que ele aumente o chute
            if (chute < numero) printf("\n\n                                     O número é maior que %d, tente novamente.\n", chute);
 
            //Se o número chutado for maior que o correto, será recomendado que ele diminua o chute
            else if (chute > numero) printf("\n\n                                     O número é menor que %d, tente novamente.\n", chute);
            
            vidas--;
        }
        
        getchar();
        
        if(!vidas) printf("\n\033[31m                                               Você perdeu. Sinto muito, não foi dessa vez.\033[0m\n");
        else printf("\n\033[32m                                               Você venceu! Parabéns.\033[0m\n");
        printf("\n\n                                               Aperte ENTER para continuar\n");
        getchar();
        system("clear");
}


void forca(char* nome){
    printf("                                                 ☆☆ JOGO DA FORCA ☆☆ \n\n");
        
        //Matriz com as 10 palavras de até 100 caracteres que podem ser escolhidas
        char palavras[10][100] = {"cachorro", "gato", "morango", 
        "alcachofra", "andromeda", "largaticha", "curumins",
        "menina", "brasiliense", "bahia"};
        
        //String que representa a palavra a ser revelada
        char secreto[100];
        char chute;
        
        //Sorteio do index da matriz palavras
        int aleatorio = (rand() % 10) + 1;
        int vidas = 5;
        int acertou;
        int venceu;
        
        //Váriavel para guardar as tentativas feitas
        char tentativas[vidas*2];
        tentativas[0] = '\0';
        int contador = 0;
        
        //Inicializa o secreto como X vezes a quantidade de letras da palavra escolhida
        for(int i = 0; i < strlen(palavras[aleatorio]); i++){
            secreto[i] = 'X';
        }
        
        //Adicionar o terminador nulo!
        secreto[strlen(palavras[aleatorio])] = '\0';
        
        //Loop que durara enquanto o jogador tiver vida > 0
        while(vidas){
            
            //limpa a tela para o proximo chute e reseta o valor da variavel acertou
            acertou = 0;
            venceu = 1;
            
            printf("Restam %d vidas\n                                                                                        Tentativas: %s\n", vidas, tentativas);
            printf("                                                       %s\n\n", secreto);
            printf("                                               Fale uma letra, %s: ", nome);
            
            scanf("%c", &chute);
            
            //O \n residual é retirado
            getchar();
            
            
            //O programa verifica se há, na palavra escolhida, o chute do jogador
            for(int i = 0; i < strlen(palavras[aleatorio]); i++){
                
                //Se sim, revela a letra no secreto
                if(palavras[aleatorio][i]==chute){
                   secreto[i] = chute;
                   
                   //Se não, ele não perde vida
                   acertou = 1;
                }
                
            }
            
            //Checar se o jogador venceu ou não no estagio atual
            for(int i = 0; i < strlen(palavras[aleatorio]); i++){
                //Checagem letra por letra
                if(secreto[i] != palavras[aleatorio][i]) venceu = 0;
            }
            
            //Se o jogador venceu, o jogo acabou!
            if(venceu) break;
            
            //Se não acertou nenhuma letra
            if(!acertou){

                //De 2 em 2, para permitir a virgula
                tentativas[contador] = chute;
                //No primeiro chute, não ha virgula
                if(contador > 1) tentativas[contador-1] = ',';
                tentativas[contador+1] = '\0';
                //Pula duas casas para caber a virgula
                contador += 2;
                
                //Ele perde uma vida se não acertou nenhuma letra
                vidas--;
            } 
            
            system("clear");
        }
        
        printf("                                               A palavra era %s\n", palavras[aleatorio]);
        if(!vidas) printf("\n\033[31m                                               Você perdeu Sinto muito, não foi dessa vez.\033[0m\n");
        else printf("\n\033[32m                                               Você venceu! Parabéns.\033[0m\n");
        printf("\n\n                                               Aperte ENTER para continuar\n");
        getchar();
        system("clear");
            
}


int main()
{
    srand(time(NULL));
    printf("==============================================================================================================================================\n");
    printf("                                               ☆☆ BEM VINDO(A) AO MUNDO DOS JOGOS☆☆ \n");
    printf("            Está entediado? Não sabe como passar o tempo? Temos a solução para você. Ficamos muito felizes com a sua chegada!\n\n");
    printf("==============================================================================================================================================\n");
    printf("                                                      Aperte ENTER para continuar\n");
    getchar();
    system("clear");
    
    //Strings que representam o jogo escolhido e o nome do jogador
    int jogo = 0;
    char nome[100];
    
    printf("Escreva o seu nome: ");
    //Ler nome com espaço
    fgets(nome, 100, stdin);
    //O programa vai parar de ler quando encontrar o \n
    nome[strcspn(nome,"\n")] = 0;
    system("clear");
    
    //Enquanto o jogador não escolher sair do programa, ele continuará no loop
    while (jogo!=3) {
        
    printf("                                     ========================================================================\n");
    printf("                                     =                                                                      =\n");
    printf("                                     =                                                                      =\n");
    printf("                                         Qual jogo você deseja escolher, %s? Digite o número do jogo.  \n", nome);
    printf("                                     =                                                                      =\n");
    printf("                                     =   1) Jogo da forca                                                   =\n");
    printf("                                     =   2) Adivinhe o número                                               =\n");
    printf("                                     =   3) Sair                                                            =\n");
    printf("                                     =                                                                      =\n");
    printf("                                     =                                                                      =\n");
    printf("                                     ========================================================================\n");
    scanf("%d", &jogo);
    getchar();
    system("clear");
    
     if (jogo==1) {
        //Função que leva para o jogo 1
        forca(nome);
     }
     
     if (jogo == 2) {
        //Função que leva para o jogo 2
        adivinha(nome);
     }
    }
    
    return 0;
}