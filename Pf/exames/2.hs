maisvezes :: Int -> [Int]
maisvezes a = a : b : maisvezes(b*2)
              where b = a+2
              
 
data ArvC a = Vazia | No a Int (ArvC a) (ArvC a)            
              
nelem ::  ArvC a -> Int
nelem Vazia = 0
nelem (No a b esq dir) = 1 + nelem esq + nelem dir

injust :: [Int] -> Int
injust xs = length( filter(\x -> x>=10 && x<15) (xs))
