module Main where

  main :: IO()
  main = print(reverse2[1,2,3,4,3,4,5,6])
  
  reverse'::[a]->[a]
  reverse' (x:xs) = foldr f [] (x:xs) where

    f::a->[a]->[a]
    f x ys = ys++[x]


  reverse1::[a]->[a]
  reverse1 = foldr(\x ys -> ys++[x])[]

  reverse2::[a]->[a]
  reverse2 = foldr f [] where
    f::a->[a]->[a]
    f = (\x ys -> ys++[x])


  riffle0 :: [a] -> [a] -> [a]
  riffle0 xs ys = foldr f k xs ys where
    k :: [a] -> [a]
    k = id
    f :: a -> ([a] -> [a]) -> [a] -> [a]
    f x h [] = x : h []
    f x h (y : ys) = x : y : h ys

  riffle1 :: [a] -> [a] -> [a]
  riffle1 xs ys = concat(map(\(x,y)->[x,y]) (zip xs ys))
