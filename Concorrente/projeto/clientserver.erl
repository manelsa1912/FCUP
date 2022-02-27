-module(clientserver).
-compile(export_all).

start1() -> register(simpleTable, spawn(fun() -> loop() end)).

do_this_once() -> rpc({do_this_once}).

start() -> rpc({start}).

reset_tables() -> rpc([reset_tables]).

livros(CC) -> rpc([livros,CC]).

emprestimos(Bname) -> rpc([emprestimo,Bname]).

requisitado(Bookcode) -> rpc([requisitado,Bookcode]).

codigos(Bname)-> rpc([codigos,Bname]).

numRequisicoes(CC) -> rpc([numRequisicoes,CC]).

add_request(PersonId,BookId) -> rpc([add_request,PersonId,BookId]).

remove_request(PersonId,BookId) -> rpc([remove_request,PersonId,BookId]).

rpc(Q) ->
    Ref = make_ref(),
    simpleTable ! {self(),Ref, Q},
    receive
	{simpleTable,Ref, Reply} ->
	    Reply
    end.

loop() -> 
    receive
	
    {From, Ref,{do_this_once}} ->  
	    From ! {simpleTable,Ref, database:do_this_once()},
	    loop();

   
    {From, Ref,{start}} ->  
	    From ! {simpleTable,Ref, database:start()},
	    loop();

    
    {From, Ref,{reset_tables}} ->  
	    From ! {simpleTable,Ref, database:reset_tables()},
	    loop();

    
    {From,Ref, {livros,CC}} ->  
	    From ! {simpleTable,Ref, database:livros(CC)},
	    loop();

   
    {From,Ref, {emprestimos,Bname}} ->  
	    From ! {simpleTable,Ref, database:emprestimos(Bname)},
	    loop();


    {From,Ref, {requisitado,Bookcode}} ->  
	    From ! {simpleTable,Ref, database:requisitado(Bookcode)},
	    loop();


    {From,Ref, {codigos,Bname}} ->  
	    From ! {simpleTable,Ref, database:codigos(Bname)},
	    loop();

    {From,Ref, {numRequisicoes,CC}} ->  
	    From ! {simpleTable,Ref, database:numRequisicoes(CC)},
	    loop();


    {From,Ref, {add_request,PersonId,BookId}} ->  
	    From ! {simpleTable,Ref, database:add_request(PersonId,BookId)},
	    loop();


    {From,Ref, {remove_request,PersonId,BookId}} ->  
	    From ! {simpleTable,Ref, database:remove_request(PersonId,BookId)},
	    loop()
    end.

