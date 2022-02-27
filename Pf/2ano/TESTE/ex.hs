--Aula 1 e 2 -> Definições de funções simples

-- 1
inc x =x+1
quadrado x=x*x
dobro x=x+x
media x y = (x+y)/2
fatorial n = product [1..n]

-- 2
triangulo a b c= if(a<(b+c))&&(b<(a+c))&&(c<(a+b)) then True else False

-- 3
perimetro a b c = (a+b+c)/2
area a b c = sqrt(s*(s-a)*(s-b)*(s-c))
       	     where s = perimetro a b c
-- 4
metade xs = [take (size `div` 2) xs] ++ [drop (size `div` 2) xs]
       where size = length xs

metade2 xs = splitAt (length xs `div` 2) xs
-- 5a
-- drop((length [1,2,3,4,5])-1) [1,2,3,4,5] e igual a last[1..5]
-- 5b
eliminar_u xs= reverse ((drop 1 (reverse xs)))

-- 6a
binom n k = (fatorial n) `div` ((fatorial k)*(fatorial(n-k)))

-- 6b
binom2 n k= (product[(k+1)..n]) `div` (product[1..(n-k)])
--7

--a
max3 :: Int -> Int -> Int -> Int
max3 a b c = max (a (max b c))
min3 :: Int -> Int -> Int -> Int
min3 a b c = min (a (min b c))
--b
max :: Int -> Int -> Int
max x y = if(x>=y) then x else y
min :: Int -> Int -> Int
min x y = if(x==y) then x else y
--8
--a
maxOccurs :: Integer -> Integer -> (Integer,Integer)
maxOccurs x y = (if(x>=y) then x else y, if(x==y) then 2 else 1)
--b
orderTriple :: (Integer,Integer,Integer) -> (Integer, Integer,Integer)
orderTriple a b c = (min3 a b c, d, max3 ab c)
                    where d = (a+b+c) - ( max3 a b c + min3 a b c)
                          
--9
classifica :: Int -> String
classifica x |x<=9= "Reprovado"
             |x<=12 = "Suficiente"
             |x<=15 = "Bom"
             |x<=18 = "Muito Bom"
             |x<=20 = "Excelente"
             |otherwise= "ERRO"
--10
xor :: Bool -> Bool -> Bool
xor c b | False && True = True
        | True && False = True
        |otherwise = False
--11
--condicionais
safetail :: [a] ->[a]
safetail xs= if null xs then xs else tail xs
--guardas
safetail_g ::[a]->[a]
safetail_g xs |null xs=xs
	      |otherwise = tail xs

--padroes
safetail_p :: [a]->[a]
safetail_p []= []
safetail_p (_:xs) = xs

-- 12a
verificar :: [a]->Bool
verificar xs |(a==0||a==1||a==2)=True
	     |otherwise = False
	     where a= length xs

-- 12b
verificar2 ::[a]->Bool
verificar2 []= True
verificar2 [a]=True
verificar2 [a,b]=True
verificar2 _ = False
----------------------------------------------------------------------
--Aula 2 -> Tipos e Classes
-- 14
--a  ['a','b','c'] :: [char]
--b  ('a','b','c') :: (char,char,char)
--c  [(False,'0'),(True,'1')] :: [(Bool,char)]
--d  ([False,True],['0','1']) :: ([Bool],[char])
--e  [tail,init,reverse] :: [[a]->[a]]
--f  [id, not] :: [Bool->Bool]

--15
--1 f :: (Int, Int) -> Int
--2 f :: Int -> Int  g :: Int -> Int
--3 f :: Int -> (Int,Int) g:: Int
--4 f :: ([Int] -> [Int]) -> [Int] -> Int  g :: [Int] -> [Int]
--5 f :: (Int, Int) -> [Int -> Int]

--16 f :: a -> (Int -> [Int])  g :: a
-----------------------------------------------------------------
--Aula 3 -> Listas em compreensão
-- 22
somaq = sum[x^2| x<-[1..100]]

-- 23
-- a)
aprox :: Int -> Double
aprox n = sum[((-1)^fromIntegral(x)) / (2*fromIntegral(x)+1)| x<-[0..n]]

-- b)
--msm coisa em a) so q em notaçao diferente

-- 24
divprop :: Int -> [Int]
divprop n = [x | x <- [1..(n-1)], n `mod`x==0]

-- 25
perfeitos :: Int -> [Int]
perfeitos n = [x | x<-[1..n], sum(divprop x) == x]

-- 26

primo :: Int -> Bool
primo n | tamanho == 1 =False
        | tamanho <= 2 =True
        | otherwise = False
        where tamanho = length(divprop n ) +1
-- 27

pascal :: Int -> [[Int]]
pascal n = [[binom x y | y<-[0..x]] | x<-[0..n]]

-- 28

dotprod :: [Float]-> [Float]-> Float
dotprod x y = sum[(x!!n)*(y!!n) | n<-[0..(length(x)-1)]]

-- 29
pitagoricos :: Int -> [(Int,Int,Int)]
pitagoricos n = [(x,y,z) | x <-[1..n], y<-[1..n], z<-[1..n], x^2 + y^2 == z^2]

--------------------------------------------------------------------------------
--Aula 4 e 5 -> Definições recursivas e processamento de listas

-- 30
-- a
fatoriaal x |x>0=x*fatorial(x-1)
	          |otherwise =1
-- b
range :: Integer->Integer->Integer
range a b |a<=b = a*range(a+1) b
          |otherwise = 1
-- c
fatorial2 :: Integer -> Integer
fatorial2 n = range 1 n

-- 31
mult (a,b) |b>0 = a + mult(a,b-1)
           |otherwise = 0
-- 32
--1º
rq ::Int -> Int
rq n =mq n n
--2º
mq :: Int->Int->Int
mq n k |k*k <= n = k
       |otherwise= mq n (k-1)
-- 33
--1º
f ::Integer -> Integer
f 5 =1000 --exemplo
f n = -(n)*(n) --FUnçao exemplo
--2º
max2 ::Integer->Integer-> Integer
max2 x n |x>n=n
         |otherwise = n

--3º
maxFun ::(Integer->Integer)->Integer->Integer
maxFun f n |n>0 = max2(f n) (maxFun f (n-1))
           |otherwise = f n
-- 34
--1º
g ::Integer->Integer
g n = n --exemplo

--2º
anyzero g (-1)=False
anyzero g n | f n ==0 = True
            |otherwise = anyzero g (n-1)
-- 35
sumfun f n |n>= 0 = f n + sumfun f (n-1)
           |otherwise = 0
--36
mdc a b |b==0 = a
        |otherwise = mdc b (a `mod` b)
-- 37
recursiva x |x>0 = 2*recursiva(x-1)
	    |otherwise = 1
-- 38
--a
annd (x:xs) |x==False = False
            |otherwise = annd xs
annd []=True

--b
oor (x:xs) |x==True=True
           |otherwise=oor xs
--oor []=[]

--c
concaat (x:xs)= x ++ concaat(xs)
concaat [] =[]

--d
replicaate i n |i>0=[n] ++ replicaate (i-1) n
               |otherwise = []

--e
(!!!) (x:xs) n | n>0 = (!!!) xs (n-1)
               |otherwise = x

--f
eleme a (x:xs) |x==a=True
               |xs==[]=False
               |otherwise=eleme a xs
--39
--40
minusculas :: String -> Int
minusculas str = length [c | c<-str,c>='a' && c<='z']
maiusculas :: String -> Int
maiusculas str = length [c | c<-str, c>='A' && c<='Z']
algarismo :: String -> Int
algarismo str = length [c | c<-str, c>='0' && c<='9']
forte ::String -> Bool
forte str | maiusculas >=1 && minusculas >=1 && algarismo str >=1 && length str >=8 = True
          |otherwise = False

-- 41
remove_ele :: Eq a=> [a]->[a]
remove_ele []=[]
remove_ele (x:xs) = x:[xs!!n |n<-[0.. (length xs)-1], (xs!!n)/=x]  
nub :: Eq a => [a]->[a]
nub []=[]
nub (x:xs) = x: nub(remove_ele xs)

-- 42
atum :: a -> [a] -> [a]
atum c (x:xs) | null xs = x : []
              | otherwise = x : c : atum c xs

numEqual :: Int->Int->Int->Int
numEqual x y z |(x==y)&&(x==z)=3
               |(x==y)&&(x/=z)=2
               |otherwise=1
nat_zip :: [a]-> [(Int , a)]
nat_zip xs = reverse(zip[3,2..] (xs))

quadrados :: [Integer]->[Integer]
quadrados []=[]
quadrados (x:xs)= (x^2): quadrados (xs)

quadrados2 :: [Integer]->[Integer]
quadrados2 (x:xs) =[x^2| y<-[1..n]]
                   where n= length(xs)  -1
--43
--a
insert :: Ord a => a -> [a] -> [a]
insert l [] = [l]
insert l (x:xs)|l>x=x:insert l xs
               |l<=x=l:insert(x:xs)
--b
insertsort :: [Int] -> [Int]
insertsort [x] = [x]
insertsort (x:xs) = insert x ( insertsort xs)

--44
--a
minimun :: Ord a => [a] ->a
minimum [x] = x
minimum (x:y:xs) | x<y = minimum (x:xs)
                 |otherwise = minimum (y:xs)

--b
delete :: Eq a => a -> [a] -> [a]
delete a [] = []
delete a (x:xs) |a==x = xs
                |otherwise = x :delete xs
--c
ssort :: Ord a => [a] -> [a]
ssort []= []
ssort [x] = [x]
ssort (x:xs) = minimum (x:xs) : ssort (delete(minimum(x:xs))(x:xs))

--45
--a
merge :: Ord a => [a] -> [a] -> [a]
merge [] []=[]
merge xs []=xs
merge [] ys=ys
merge (x:xs) (y:ys) |x<y = x:merge xs (y:ys)
                    |otherwise = y:merge (x:xs) ys
--b
msort :: Ord a => [a] -> [a]
msort [] =[]
msort xs |(length xs) > 1 = merge (msort ls) (msort rs)
         |otherwise = xs
         where (ls,rs) = metades xs
--46
bits :: Int -> [[Bool]]
bits 0 = [[]]
bits n = [b:bs | b<-[True,False], bs <-bits (n-1)]

--47
permutations :: [a] -> [[a]]
permutations [] = [[]]
permutations p = [x:xs | x<-p ,xs <-permutations(delete x p)]

--48
e48 :: (a->b)-> (a->Bool) -> [a] -> [b]
e48 f p xs = map f( filter p xs)

--49
--a
concat2 :: [a] -> [a] -> [a]
concat2 l1 l2 = foldr (:) l2 l1
--b
con :: [[a]] ->[a]
con [b,a] = foldr (:) b a
--c
reverses :: [a] -> [a]
reverses a = foldl (\ys x -> x: ys) [] a
--d
reverse2 :: [a] -> [a]
reverse2 s = foldl (\xs x -> x:xs) [] s
--e
elem1 :: Eq a => a -> [a] -> Bool
elem1 s xs  = any (s==) xs
--50
dec2int :: [Int] -> Int
dec2int a = foldl(\ys yss -> (10*ys) + yss) 0 a
--51
zipWith' :: (a-> b -> c) -> [a] -> [b] -> [c]
zipWith'f (x:xs) (y:ys) = f x y : zipWith' f xs ys
--52
isort :: Ord a => [a] -> [a]
isort []= []
isort (x:xs) = insert x (isort xs)

isort' :: Ord a => [a] -> [a]
isort' l = foldr insert [] l
--53
--a
shift :: Ord a => [a] -> [a]
shift [] = []
shift (x:xs) = xs++[x]

--54
--a
maximum', minimum' :: Ord a => [a] -> a
maximum2, minimum2 :: Ord a => [a] -> a
maximum' xs = foldl1 max xs
minimum' xs = foldl1 min xs
maximum2 xs= foldr1 max xs
minimum2 xs = foldr1 min xs
--b
foldr1 f (x:xs) = foldr f x xs
foldl1 f (x:xs) = foldl f x xs

--55
--a
add :: (Eq a ,Enum a , Num a) => a -> a -> a
add i 0 = i
add i j = succ (add i (pred j))

mult :: (Eq a , Enum a, Num a) => a -> a ->a
mult _ 0 = 0
mult 0 _ = 0
mult i j = mult i (pred j) + add 0 i

exp' :: (Eq a , Enum a, Num a) => a->a->a
exp' 0 j = 0
exp' i 0 =1
exp' i j = mult i 1 * exp' i (pred j)

--b
foldi :: (a->a) ->a -> Integer -> a
foldi f q 0 = q
foldi f q i = f (foldi f q (pred i))

add' :: Num a => a->a->a
add' i j = foldi (+j) i 1

mult' :: Num a => a-> a->a
mult' i j = foldi (*i) j 1

exp'' :: Num a => a->a->a
exp'' i j = foldi (*i) 1 j
--c
fact :: Num a => Int -> a
fact i = first ( foldi (\(x,y) -> (x*y,y+1)) (1,1) i)
--------------------------------------------------------
--Aula 8 -> Listas infinitas

--58
--fact :: [Integer]
--fact = 1 : [toInteger(x+1) * fact !! x | x <-[0..]]

--fibsN :: Integer -> Integer -> [Integer]
--fibsN x y = x : y : fibs (x+y) (x+y+y)
--fibs = fibsN 0 1


--59
potencias2 :: [Integer]
potencias2 = map (2^) [1,2..]
potencias3 :: [Integer]
potencias3 = map (3^) [1,2..]
merge_aux :: [Integer] -> [Integer] -> [Integer]
merge_aux [] [] = []
merge_aux [] xs = xs
merge_aux x [] = x
merge_aux (x:xs) (y:ys) | x<y = x: merge_aux xs (y:ys)
                        | otherwise = y : merge_aux (x:xs) ys

merge :: [Integer]
merge = merge_aux potencias2 potencias3

--60
somas_aux :: Integer -> [Integer] -> [Integer]
somas_aux n (x:xs)  = [(n+x)] ++ somas_aux (n+x) xs
somas :: [Integer] -> [Integer]
somas xs = somas_aux 0 xs
--ou
somas :: [Int] -> [Int]
somas xs = 0: zipWith (+) (somas xs) xs

--64
scanl_aux :: (Int -> Int -> Int) -> Int -> [Int] -> [Int]
scanl_aux f n (x:xs) = [(f n x)] ++ scanl_aux f (f n x) xs
scanl :: (Int -> Int -> Int) -> Int -> [Int] -> [Int]
scanl f n xs = [n] ++ scanl_aux f n xs
----------------------------------------------------------------
--Aula 9  -> Programas interactivos

--65
elefantes :: Int -> IO()
elefantes n = elefanteAux 1 n
main = elefantes 5
elefanteAux :: Int -> Int -> IO()
elefanteAux j n |j==n = return()
elefanteAux j n = do putStrLn("Se " ++ show(j) ++ " incomodam muita gente,")
                     putStrLn(show(j+1) ++ " elefantes incomodam muito mais!")
                     elefanteAux (j+1) n
--67
--trocarInput :: IO()
--trocarInput = do
--  x<-getLine
--  putStr (reverse x)
--  if x=="\n" then
--    return ()
--  else
--    trocarInput
-------------------------------------------------------------
--Aula 10 -> Árvores de pesquisa

data Arv a = Vazia
--data Arv = Folha Int
      --   | No Arv Int Arv
--data Vazia = []
           | No a (Arv a) (Arv a)

--71 -> Soma de valores da arvore
sumArv :: Num a => Arv a -> a
sumArv Vazia = 0
sumArv (No a esq dir) = a + (sumArv esq) + (sumArv dir) 
-- a = No 6 (No 3 Vazia Vazia) (No 7 Vazia (No 8 Vazia Vazia))
-- para testar este temos de criar arvore de exemplo como em cima

--72 -> listar elementos de uma arvore de pesquisa por ordem DECRESCENTE

listar :: Arv a -> [a]
listar Vazia = []
listar (No a esq dir) = listar dir ++ [a] ++ listar esq  -- a arvore ja esta ordenada
                                                         -- pq e de pesquisa
--73 -> lista ordenada de valores da arvore no nivel n
nivel :: Int -> Arv a -> [a]
nivel _ Vazia = []
nivel 0 (No a _ _) =[a]
nivel _ (No a Vazia Vazia) =[]
nivel n (No a esq dir) = nivel (n-1) esq ++ nivel (n-1) dir


--75 -> funçao aplicada a cada valor duma arvore
--map :: (a -> b) -> [a] -> [b]
--map f []= []
--map f (x:xs)= f x : map f xs
mapArv :: (a -> b) -> Arv a -> Arv b
mapArv f Vazia= Vazia
mapArv f (No a esq dir) = No (f a) (mapArv f esq) (mapArv f dir)
--------------------------------------------------------------------
--Aula 11 -> Definições de tipos

--79
--a)
data Shape = Circle Float | Rectangle Float Float

--b)
per :: Shape -> Float
per ( Circle r ) = 2*pi*r
per ( Rectangle a b ) = 2*a + 2*b

--80
data Box = Box Ponto Ponto
type Ponto = (Integer,Integer)

--areaRect (Box (x1,y1) (x2,y2)) = ((y2-y1) * (x2-x1))

--corners :: Box -> [Ponto]
--corners (Box (x1,y1) (x2,y2) = [(x1,y1),(x1,y2),(x2,y1),(x2,y2)]

inside :: Ponto -> Box -> Bool
inside (x,y) (Box (x1,y1) (x2,y2)) = ((x1 <= x) && (x<=x2) && (y1<=y) && (y<=y2))
           
intersectRect :: Box -> Box -> Bool
intersectRect b1 b2
  = or ([inside p b2 | p<-corners b1} ++ [inside p b1 | p<-corners b2])
-----------------------------------------------------------------------------


-- [sum[x*x] | x<-[1..100]]
