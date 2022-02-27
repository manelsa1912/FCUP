(+++):: [a]->[a]->[a]
(+++) (xs) (ys) = foldr(\x acc -> x:acc) ys xs


concat2:: [[a]] -> [a]
concat2 (x:xss) = foldr (\x acc -> x ++ acc)[] xss


elem:: Eq a => a -> [a] -> Bool
elem   xs = any (==x) xs 