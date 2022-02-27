data Arv a = Vazia | No a (Arv a)(Arv a)
             deriving(Show)

arv1 :: Arv Int
arv1 = No 10 (No 5 (No 3 (No 1 Vazia Vazia) Vazia)
                   (No 8 (No 7 Vazia Vazia)(No 9 Vazia Vazia)))  
             
             (No 17 (No 12 Vazia Vazia)
                    (No 21 (No 20 Vazia Vazia)(No 25 Vazia Vazia))) 
                    
                    
                   
sum2 :: Num a => [a] -> a
sum2 [] = 0
sum2 (x:xs) = x + sum2 xs



sumArv :: Num a => Arv a -> a
sumArv Vazia = 0
sumArv (No x esq dir) = x + sumArv esq + sumArv dir



listar :: Arv a -> [a]
listar Vazia = []
listar (No x esq dir) = listar dir ++ listar esq ++ [x]


nivel :: Int -> Arv a -> [a]
nivel n Vazia = []
nivel n (No x esq dir) | n == 0 = [x]
                       | otherwise = nivel (n-1) esq ++ nivel (n-1) dir
