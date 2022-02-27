factorial :: [Integer]
factorial = 1 : [ n*m | (n,m) <- zip factorial [1..] ]