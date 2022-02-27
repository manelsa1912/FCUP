triangulo a b c = a<b+c && b<a+c && c<a+b


per a b c = (a + b + c)/2



area a b c= let s =per a b c in
   sqrt(s*(s-a)*(s-b)*(s-c))

