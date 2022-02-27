inverte :: IO()
inverte = do s <- getLine
             let s' = reverse s
             putStrLn s'
             inverte
