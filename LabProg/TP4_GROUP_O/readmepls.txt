
           ----------------------x-X-x-----------------------                       
            \\                                            //
     XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX
     XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX
     XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX
     XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX
     XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX
            //                                            \\ 
           ----------------------x-X-x-----------------------

                             by 201805273



Compilação e Execução:

 *Para compilar e executar o BattleShip normal passar os segunintes comandos para o terminal:
      make normal
      ./BattleShip

 *Para compilar e executar o BattleShip com a implemtaçao de quad tree passar os segunintes comandos para o terminal:
      make normal
      ./BattleShip2
 
 *Caso seja preciso recompilar por algum motivo, o comando para limpar os ficheiros ja compilados é:
      make clean


---------------------//-----------------------//-------------------------//---------------------------//------------------------------//..........


Como jogar:

-Selecionar o tamanho do mapa;

-Inserir o numero de barcos por jogador;

-Seleção de colocaçao de barcos para o jogador 1 e de seguida para o jogador 2:

      *automatica (apresenta diretamente o mapa criado com baros colocados aleatoriamente);

      *manual: Selecionar o tipo de barco a colocar
               Selecionar a rotação do barco escolhido
               Colocação do barco no mapa (a coordenada de input é a coordenada central do bitmap)
               nota: É obrigatório a colocação de pelo menos um barco de cada tipo

-Inicio da batalha:

   *No início de cada turno o jogador tem a opção de analisar o próprio mapa antes de atacar o adversário
   (o ponto acima tem como objetivo premitir um jogo 2player local, em que o adversario nao vai "espreitar" para o meu mapa)

   *De seguida o jogador tem de selecionar uma coordenada para atacar o mapa adversario;
   
   *o programa avisa o que aconteceu. Existem três opções. Falhamos, acertamos ou afundamos um barco;

   *para afundar um barco adversario é necessário disparar em todas as coordenadas do barco;
   
   *O jogador que tiver todos os navios afundados perde.


-O mapa:

   *Esitem dois tipos de mapas:

      -O meu mapa onde: 0-Espaço Vazio
                        3-Espaço Vazio atingido
                        1-Barco nao atingido
                        2-Barco atingido
                        2-Barco afundado
      
      -O mapa adversario onde:0-Espaço por disparar
                              2-Espaço Vazio
                              1-Barco inimigo
                              1-Barco enimigo afundado


-Os barcos(em rotação de 0º):
   
   *Cargueiro    *Couraça      *Cruzeiro/Submarino      *Destruidor

   0 0 0 0 0      0 0 0 0 0         0 0 0 0 0            1 0 0 0 0                   
   0 0 0 0 0      0 0 0 0 0         0 0 0 0 0            1 0 0 0 0
   1 1 1 1 1      1 1 1 1 0         0 1 1 1 0            1 1 1 1 1
   0 0 0 0 0      0 0 0 0 0         0 0 0 0 0            1 0 0 0 0
   0 0 0 0 0      0 0 0 0 0         0 0 0 0 0            1 0 0 0 0
                 

---------------------------//------------------------------------//------------------------------//---------------------------//---------------------
   
Como funciona?

Existem vários ficheiros, divididos da seguinte forma:
   
   *makefile - o ficheiro que faz a compilação dos restantes;
   
   Para o BattleShip normal:
         
         *barcos.c e barcos.h - Estes ficheiros possuem as structs e funções que são precisas para todas as interações com os barcos do jogo.
         
            A struct Boat guarda a informação de um barco(o seu bitmap 5x5,qual o tipo de barco, a rotação dele e um contador de pontos atingidos para saber quando está afundado).
            
            As funções são as seguintes:  build_boat - constroi um barco (nota:recebe a rotação ao mesmo tempo e cria diretamente um bitmap na rotação certa);
                                          print_boat - imprime uma pre-visualização do barco criado.

         
         *mapas.c e mapas.h - os ficheiros que contém a informação dos mapas do jogo (structs e funções).

            Existem duas structs para o mapa: Cell - É a estrutura de cada coordenada do mapa;
                                                   - Possui um ref_shot que guarda a situação da coordenada naquele momento (se foi atingida ou não)
                                                   - Um apontador para um barco caso esteja lá colocado um barco
                                             
                                              Mapa - Estrutura do mapa todo;
                                                   - Guarda o tamanho do mapa;
                                                   - Possui um array em que cada posição é um apontador para cada coordenada cell;
            
            As funções sao as seguintes:  new_map - constroi um mapa vazio;
                                          print_own-map - imprime o nosso mapa naquele momento;
                                          print_enemy_map - imprime o mapa inimigo com os barcos escondidos para quando for o nosso turno;
                                          shot - altera os valores do ref_shot da cell quando o enimigo seleciona uma coordenada para atacar ou quando atacamos o enimigo;

         
         *util.c e util.h - São ficheiros que possuem funções precisam de ambas partes(barcos e mapas).

            As funções são as seguintes:  place_boat - coloca um barco no mapa;
                                          build_automatic_map - coloca aleatoriamente todos os barcos no mapa.

         
         *BattleShip.c - É o ficheiro principal onde está a main. Também possui algumas funções que precisam de ler um input diretamente.
         
            As funçõesc sao as seguintes: main - função principal do programa;
                                          build_own_map - a função que vai permitir ao jogador escolhar como criar o pŕoprio mapa. Ela lê o input que direciona para as funções anteriores.
                                          turn - A função que corre no nosso turno. Permite analisar o nosso mapa antes de atacar e recebe o input do tiro que vamos diparar a seguir. Faz todos os prnts necessários para vermos o que esta a acobtecer;



   Para o BattleShip de quad tree:
         
         *barcos.c e barcos.h - Ficheiros iguais aos de cima;

         
         
         *quadtree.c e quadtree.h - Ficheiros que possuem a informaçao e funçoes da quadtree (que sera o mapa do jogo)

            Existem duas structs para o mapa: QD_NODE - estrutura que representa um no da arvore;
                                               Point - estrutura que guarda os valores das coordenadas x e y de um ponto ou centro de um no;
                                               Cell2 - Estrutura que guarda o barco naquele no,assim como um ref_shot, que diz se o barco foi atingido ou nao.

            As funçõesc sao as seguintes: build_new_node - constroi um no folha vazio;
                                          build_leafs - muda um no folha para no interno e gera nos folha dele;
                                          search_point - pesquisa um ponto na arvore. Se encontrar retorna o no onde está.
            
         
        
         *enemy.c e enemy.h - icheiros que possuem a informaçao e funçoes de um array de chars que guarda a informaçao para mandar para o adversario de modo a poder jogar  
            
            A struct Enemy tem o tamanho do lado do mapa, um array com todas as posiçoes e um total shotcount para determinar o fim do jogo
         
            As funçõesc sao as seguintes: build_enemy - constroi uma estrutura nova;
                                          print_enemy_quadmap - printa o mapa que o adversario vai ver.
         
         *player.c e player.h - Ficheiros que guardam a informaçao de um jogador(o seu mapa e o mapa do advresario).

          
         *quadutil.c e quadutil.h - São ficheiros que possuem funções precisam de ambas partes(barcos e arvores).

            As funções são as seguintes:  insert poin in leaf - coloca um ponto numa foha;
                                          insert boat - coloca todos os pontos do barco na arvore;
                                          quad shot - altera o estado da coordenada selecionada para disparar 
                                          print my quad map- printa a arvore do jogador sobre forma de mapa
                                          build automatic map - constroi um mapa aleatorio;
                                          
         *BattleShip2.c - É o ficheiro principal onde está a main. Também possui algumas funções que precisam de ler um input diretamente.
         
            As funçõesc sao as seguintes: main - função principal do programa;
                                          build_own_quadmap - a função que vai permitir ao jogador escolher como criar o pŕoprio mapa. Ela lê o input que direciona para as funções anteriores.
                                          quad_turn - A função que corre no nosso turno. Permite analisar o nosso mapa antes de atacar e recebe o input do tiro que vamos diparar a seguir. Faz todos os prnts necessários para vermos o que esta a acobtecer;

--------------//---------------------//----------------//-------------------//--------------//-------------------//------------------//---------------------//---------------------//------------------------//-------------//-----------------//---------

Made by Manuel da Silva Sá - up201805273
