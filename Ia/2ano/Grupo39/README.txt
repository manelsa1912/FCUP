O problema foi implemetado em C++ logo
para o compilar temos que executar os 
seguintes comandos no terminal

g++ -o a search.cpp main.cpp Map.cpp
./a

Após a execução destes seguir as instrucoes

--------------------------------

- [x] 1) - gera n pontos com coordenadas entre (-m,-m) e (m,m)
- [x] 2) a) - cria uma permutação aleatória
- [x] 2) b) - aplica a heurística nearest-neighbour a partir de um nó aleatório 
- [X] 3) - uma funcao denominada "two_exchange" que dado um candidato s retorna a sua vizinhança retirando retas concorrentes
- [ ] 4) a) - aplicar melhoramento iterativo onde escolhe o vizinho com menor perimetro
- [ ] 4) b) - aplicar melhoramento iterativo onde escolhe o primeiro vizinho
- [ ] 4) c) - aplicar melhoramento iterativo onde escolhe o vizinho com menos conflitos
- [ ] 4) d) - aplicar melhoramento iterativo onde escolhe um vizinho aleatorio

--------------------------------

Na aplicacao do metodo two_exchange e hill_climbing com pontos aleatorios temos uma falha 
na alocacao de memoria que nos impossibilita de avancar com a sua execuacao 

Estes erros nao sao criticos visto que ambos os metodos ja funcionaram anteriormente com valores introduzidos manualmente
como por exemplo:
tamanho do mapa: 20
numero de pontos: 4
0 4 0 -4 1 0 -1 0
    X     P(0,4)
    |
    |
---X|X--- P(-1,0) e P(1,0)
    |
    |
    X     P(0,-4)


--------------------------------

Duarte Alves |  Manuel Sá
------------ | -----------
 up201805437 | up201805273