-module(database).
-import(lists, [foreach/2]).
-compile(export_all).


-include_lib("stdlib/include/qlc.hrl").

-record(user, {name, cc, adress, phone}).
-record(book, {code, bookname, authors}).
-record(requesited, {rcc, rcode}).

do_this_once() ->
    mnesia:create_schema([node()]),
    mnesia:start(),
    mnesia:create_table(user, [{attributes, record_info(fields, user)}]),
    mnesia:create_table(book, [{attributes, record_info(fields, book)}]),
    mnesia:create_table(requesited, [{type,bag},{attributes, record_info(fields, requesited)}]),
    mnesia:stop(), 
    ok.

start() ->
    mnesia:start(),
    mnesia:wait_for_tables([user,book,requesited], 20000).

livros(CC) ->
    do(qlc:q([X#book.bookname || X <- mnesia:table(book), Y <- mnesia:table(requesited),
			    Y#requesited.rcc =:= CC, 
                X#book.code =:= Y#requesited.rcode
				])).

emprestimos(Bname) ->
    do(qlc:q([X#user.name || X <- mnesia:table(user), Y <- mnesia:table(book), Z <-mnesia:table(requesited),
			    Y#book.bookname =:= Bname, 
                Y#book.code =:= Z#requesited.rcode, 
                Z#requesited.rcc=:=X#user.cc
				])).

requisitado1(Bookcode) -> 
    do(qlc:q([Y#requesited.rcode || Y <- mnesia:table(requesited),
        Y#requesited.rcode=:=Bookcode
    ])).
    
requisitado(Bookcode) ->
    Y=length(requisitado1(Bookcode)),
    if(Y>0) -> true;
    true->false
    end.


codigos(Bname)->
    do(qlc:q([X#book.code || X <- mnesia:table(book),
        X#book.bookname=:=Bname
    ])).


numRequisicoes(CC) -> 
    length(livros(CC)).


add_request(PersonId,BookId) ->
    A=requisitado(BookId),
    if(A=:=false) ->
    Row = #requesited{rcc=PersonId, rcode=BookId},
    F = fun() ->
		mnesia:write(Row)
	end,
    mnesia:transaction(F)
    end.
    

remove_request(PersonId,BookId) ->
    Bye = {requesited,PersonId,BookId},
    F = fun() ->
		mnesia:delete_object(Bye)
	end,
    mnesia:transaction(F).



do(Q) ->
    F = fun() -> qlc:e(Q) end,
    {atomic, Val} = mnesia:transaction(F),
    Val.

example_tables() ->
    [%% The shop table
     {user, "Manel", 2000, "Rua19", 963390475},
     {user, "Neticha", 2021, "Rua20", 921547989},
     {user, "Irineu", 1969, "Rua5", 915963298},
     {user, "Farao", 2020, "Rua77", 936544582},
     %% The book table
     {book, 1, "Centenario: Idade das Cinzas","Zulmira Mac"},
     {book, 2, "Liga do Foguete","Patricio Alves"},
     {book, 3, "Contra Batida: Ofensiva Global","Franco Ribero"},
     {book, 4, "O Cavaleiro de Arkham","Emanuel Silva S."},
     {book, 5, "Attack do Titã: Temporada Final","C.Teixeira"},
     {book, 6, "Attack do Titã: Temporada Final","C.Teixeira & Rosas I."},

     %requisited table
     {requesited, 2000, 1},
     {requesited, 2020, 3}

    ].



reset_tables() ->
    mnesia:clear_table(user),
    mnesia:clear_table(book),
    mnesia:clear_table(requesited),
    F = fun() ->
		    foreach(fun mnesia:write/1, example_tables())
	  end,
    mnesia:transaction(F).