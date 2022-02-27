replicates :: Int -> a -> [a]
replicates 0 y = []
replicates x y = [y] ++ replicate (x-1) y


(!!!):: [a]->Int->a
(!!!) [] _ =  error "empty list"
(!!!) (x:xs) i |i==0 = x
              |otherwise = (!!!) xs (i-1)


elem2 :: Eq a => a -> [a] -> Bool
elem2 _ [] = False
elem2 e (x:xs) | e == x = True
               |otherwise = elem2 e xs



forte:: String -> Bool
forte s = length2 && mais && menos && numr
                     where length2 = length s >= 8
		           mais = or [c >= 'A' && c <= 'Z' | c<-s]
			   menos = or [c >= 'a' && c <= 'z' |c<-s]
			   numr = or [c >= '0' && c <= '9' | c<-s]


filter1:: Eq a => a -> [a] -> [a]
filter1 x ys = [y | y <- ys, x /= y]


nub:: Eq a => [a] -> [a]
nub [] = []
nub (x:xs) = x : nub (filter1 x xs)


interperse:: a -> [a] -> [a]
interperse _ [] = []
interperse _ [y] = [y]
interpese x (y:ys) = y :x: interperse x ys
