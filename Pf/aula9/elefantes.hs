gerarString :: Int -> String 
gerarString x = "Se "++ show x ++" elefantes icomodam muita gente,\n"
               ++ show (x+1) ++ " incomodam muito mais :D"

gerarStrings :: [Int] -> [String]
gerarStrings = map gerarString


elefantes :: Int -> IO()
elefantes x = do let ss = gerarStrings [2..x-1]
                 let io = map putStrLn ss
                 sequence_ io
