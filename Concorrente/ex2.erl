-module(ex2).
-export([start/0,compute_factorial/1,factorial/2,loop/1,stop/1,status/1,start1/0,status1/1,stop1/1,factorial1/2,loop1/1]).

%1)
compute_factorial(0) -> 1;
compute_factorial(N) -> N*compute_factorial(N-1). %função factorial


loop() ->
   receive
         % comando fasctorial
      {factorial, From, M} -> From ! {response, compute_factorial(M)},
      loop()
  end.

start() ->
    spawn(fun () -> loop() end).


factorial(Server, M) ->
   % enviar um request ao server
   Server ! {factorial, self(), M}, % espera pela resposta e retorna-a
   receive {response, Result} -> Result end.


%2)

%loop(N), N é um contador de requests
 loop(N) ->
    receive
          % comando factorial
       {factorial, From, M} ->
        From ! {response,compute_factorial(M)}, loop(N+1); % no fim incrementa o N
       % comando status do server - retorna o N
       {status, From} ->
          From ! {response, N},
          loop(N); % não incrementa o N, pois só conta o numero de factoriais
       % comando stop
       {stop, From} ->
          ok
    end.

    start1() -> spawn(fun ()-> loop(0) end). 
  stop(Server) ->
    Server ! {stop, self()},
    ok.

  status(Server) ->
     %enviar um request ao server
     Server ! {status, self()},
     %espera pela resposta e retorna-a
     receive {response, Result} -> Result end.



%3)
%Altere as funções anteriores para ter vários clientes, como exemplo, a nova função de pedido de status é:

status1(Server) ->
   Ref = make_ref(), % função buit-in que gera uma nova referência
   %o cliente Ref envia um pedido ao server
   Server ! {status, self(), Ref},
   % espera pela resposta e retorna-a
   receive {response, Ref, Result} -> Result end.

stop1(Server)->
    Server ! {stop,self(),0},
    ok.

factorial1(Server, M) ->
    Ref= make_ref(), 
    Server ! {factorial,self(),Ref, M},
    receive{response,Ref,Result} -> Result end.

   loop1(N) -> receive
            % comando factorial
         {factorial, From, Ref, M} ->
            From ! {response,Ref, compute_factorial(M)},loop(N+1);
            % comando status
         {status, From, Ref} ->
            From ! {response, Ref, N},
            loop(N);
         {stop, From, Ref} ->
           ok
   end.


