aprox1 :: Int -> Double 
aprox1 n = sum [((-1)^x)/fromIntegral(2*x+1)| x<-[0..n]]

aprox2 :: Int -> Double 
aprox2 n = sum [((-1)^x)/fromIntegral((x+1)^2)| x<-[0..n]]
