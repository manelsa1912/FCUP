qsort[]=[]
qsort(h:t)=(qsort l1) ++ (h) ++ (qsort l2)
            where l1 = [x | x <- t, x <= h]
                  l2 = [x | x <- t, x > h]