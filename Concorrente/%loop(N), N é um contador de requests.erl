

%3)
%Altere as funções anteriores para ter vários clientes, como exemplo, a nova função de pedido de status é:

status(Server) ->
   Ref = make_ref(), % função buit-in que gera uma nova referência
   %o cliente Ref envia um pedido ao server
   Server ! {status, self(), Ref},
   % espera pela resposta e retorna-a
   receive {response, Ref, Result} -> Result end

   loop(N) -> receive
      receive
            % comando factorial
         {factorial, From, Ref, M} ->
            .......,loop(N+1);
            % comando status
         {status, From, Ref} ->
            From ! {response, Ref, N},
            loop(N);
         {stop, From, Ref} ->
           ok
   end.