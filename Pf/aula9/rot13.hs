import Data.Char

rot13 :: Char -> Char
rot13 c = if c == ' ' then ' '
          else
              if c >= 'A' && c <= 'M' then
                 chr (ord c + 13)
              else 
                  if c >= 'N' && c <='Z' then 
                    chr (ord c - 13)
                  else 
                      if c >= 'a' && c <= 'm' then 
                        chr (ord c + 13)
                      else chr (ord c - 13)
                      
                      
                      
cesar_io :: IO ()
cesar_io = do s <- getLine
              let s' = map rot13 s
              putStrLn s'
