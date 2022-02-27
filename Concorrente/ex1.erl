-module(ex1).
-import(lib_misc, [unconsult/2]).
-compile(export_all).


member(X,[X|R]) -> true;
member(X,[y|R]) -> member(X,R);
member(X,[]) -> false.

sum([X|R])->X+sum(R);
sum([])->0.

reverse(l) -> reverse1(l,[]).

reverse1([X|R],L)->reverse1(R,[X|L]);
reverse1([],L)->L.

map1(_,[]) -> [];
map1(F,[H|T]) -> [F(H)| map1(F,T)].

double(X) -> 2*X.

minorthree(X) ->
  X < 3.

partition(Pred, List) -> part(Pred,List,[],[]).

part(Pred,[H|R],T,F)->
    case Pred(H) of
        true -> part(Pred,R,[H|T],F);
        false -> part(Pred,R,T,[H|F])
    end;

part(Pred,[],T,F)->{T,F}.



update(File, Key, Delta) ->
    {ok, Terms} = file:consult(File),
    Terms1 = do_update(Key, Delta, Terms),
    unconsult(File ++ ".tmp", Terms1).

do_update(Key, Delta, [{Key,Val}|T]) ->
    [{Key,Val+Delta}|T].