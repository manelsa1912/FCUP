aprox::Int -> Double
aprox x = 4.0*(sum [(-1.0)^x/(fromIntegral(2*x+1)) | x <- [0..x]])


divprop :: Int -> [Int]
divprop x = [y | y <- [1..x-1], x `mod` y == 0]


perfeitos :: Int -> [Int]
perfeitos x = [y | y <- [1..x], sum(divprop y) == y]


dotprod:: [Float] -> [Float] -> Float
dotprod xs ys = sum[x*y | (x, y) <-zip xs ys]


binom n k =(product [1..n])/(product [1..k] * (product [1..(n-k)]))

linha:: Int -> [Int]
linha n =[binom (n-

pascal:: Int -> [[Int]]
pascal x = [ binom y | y <-[1..x]]




        