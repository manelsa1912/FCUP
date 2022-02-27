import System.IO

wc :: String -> String
wc s = show (length $ lines s) ++ "\t" ++ show (length $ words s) ++ "\t" ++ show (length s)


main :: IO ()
main = do s <- getContents
          let s' = wc s
          putStrLn s'