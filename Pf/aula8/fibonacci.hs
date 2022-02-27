fibonacci :: [Integer]
fibonacci = 0 : 1 : [ n+m | (n,m ) <- zip fibonacci (tail fibonacci)] 