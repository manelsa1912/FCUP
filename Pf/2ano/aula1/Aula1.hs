--ex1
inc x = x + 1
quadrado x = x*x
dobro x = x + x
media x y = (x+y)/2


--ex2
--triangulo:: Int -> Int -> Int -> Bool
triangulo a b c = if a == b + c then True else
                   if b == a + c then True else
                    if c == a + b then True else False


--ex3
--area:: Int -> Int -> Int -> Float
area a b c = sqrt(mp*(mp-a)*(mp-b)*(mp-c))
            where mp = (a+b+c)/2

--ex4
metades xs = (ts , ds) 
            where ts = take s xs
                  ds = drop s xs
                  s = (length xs)`div`2


--ex5a
last1 xs = drop r xs 
         where r = (length xs) - 1

last2 xs = xs !! r
         where r = (length xs) - 1

--ex5b
init1 xs = take r xs 
         where r = (length xs) - 1

init2 xs = reverse (tail (reverse xs))

--ex6
fat 1 = 1
fat x = x * fat (x-1)

binom n k = nf/(kf*fat (n-k))
           where nf = fat n
                 kf = fat k

--ex7
max3 a b c = if (a >= b) && (a >= c) then a else 
              if (b >= a) && (b >= c) then b else c

               