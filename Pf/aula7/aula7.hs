dec2int:: [Int] -> Int
dec2int xs = foldl (\acc x -> acc * 10 + x) 0 xs


zipwith:: (a -> b -> c) -> [a] -> [b] -> [c]
zipwith _ _[] = []
zipwith _[]_=[]
zipwith f (x:xs) (y:ys) = f x y : zipWith f  xs ys


shift:: [a] -> [a]
shift [] = []
shift (x:xs) = xs ++ [x] 

rotate:: [a]->[[a]]
--rotate xs = take(length xs)(foldr(\x acc -> acc ++ [shift(last acc)] )[xs] xs)
rotate xs = iterate shift xs
