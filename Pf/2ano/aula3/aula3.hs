aprox :: Int -> Double
aprox n = 4*sum [ func x | x <- [0..n]]
            where func x = fromIntegral ((-1)^x)/fromIntegral((2*x)+1)


aprox' :: Int -> Double
aprox' n = sqrt (12 * sum [ func x | x <- [0..n]])
            where func x = fromIntegral ((-1)^x)/fromIntegral((x+1)^2)

divdrop :: Int -> [Int]
divdrop n = [ x | x <- [1..n-1], (mod n x) == 0]

perfeitos :: Int -> [Int]
perfeitos n = [x | x <- [1..n-1], sdiv x==x]
            where sdiv x= sum (divdrop x)

primo :: Int -> Bool
primo n = length (divdrop n)==1 

--fac :: (Integral a) => a -> a
--fac n = product [1..n]

--binom :: Int->Int->Int
--binom n k =(fac n)/((fac k)*(fac n-k))


--pascal::Int -> [[Int]]
--pascal n = [fila x | x <- [1..n]]
--         where fila x = [binom x xs | xs <- [1..n]]

dotprod :: [Float]->[Float]->Float
dotprod xs ys = sum [x*y| (x,y) <-zip xs ys]