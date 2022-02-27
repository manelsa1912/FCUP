metades::[a]->([a],[a])

metades xs = let s=length xs in
             let s2= s `div` 2 in
	     (take s2 xs, drop s2 xs)