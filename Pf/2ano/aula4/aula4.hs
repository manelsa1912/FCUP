pot :: Int -> Int
pot 1 = 2
pot n = 2 * pot (n-1)

concat'::[[a]]->[a]
concat'[]=[]
concat' (x:xs)= x ++ concat'(xs)

concat'':: [[a]]->[a]
concat'' []=[]
concat'' ([]:t)= concat'' t
concat'' ((x:xs):t)= x:concat''(xs:t)

replicate'::Int -> a -> [a]
replicate' 0 _ = []
replicate' n x = x : (replicate' (n-1) x)