length2::[a]->Int

length2[] = 0
length2(x:xs)=1+length2 xs



fact:: Int -> Int

fact 0 = 1
fact n = n*fact(n-1)



rangeProduct:: Int->Int -> Int
rangeProduct n m | n==m = m
                 | otherwise = n * rangeProduct (n+1) m



mult:: Int -> Int -> Int
mult n 0 =0
mult n m = n + mult n (m - 1)




raiz':: Int -> Int -> Int
raiz' n x
   | x^2 <=n = x
   |otherwise = raiz' n (x-1)

raiz:: Int -> Int
raiz n = raiz' n n






mdc':: Int -> Int -> Int
mdc' a b = if b==0 then a 
else mdc' b (a `mod` b)


mdc:: Int -> Int -> Int
mdc (a, b):
if b=0 : a
else:  mdc (b, a%b)



