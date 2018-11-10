import Data.List


In this lecture we look at trees that allow fast access to elements.

 data ATree a = ALeaf a
             | AFork (ATree a) Int (ATree a)
  deriving Show   -- this automatically makes a Show instance

Manually, we can write this:

-- instance Show a => Show (ATree a) where
--   show (ALeaf x) = "<" ++ show x ++ ">"


 flatten :: ATree a -> [a]
 flatten (ALeaf x) = [x]
 flatten (AFork l ix r) = flatten l ++ flatten r


 mkATree :: [a] -> ATree a
 mkATree []  = error "Foolish human"
 mkATree [x] = ALeaf x
 mkATree xs  = AFork l ix r
   where (ls, rs) = splitAt (n `div` 2) xs
         n = length xs
         l = mkATree ls
         ix = length ls
         r = mkATree rs

 retrieve :: ATree a -> Int -> a
 retrieve (ALeaf x)     0 = x
 retrieve (AFork l m r) n
   | m > n     = retrieve l n
   | otherwise = retrieve r (n - m)
 retrieve _ n = error ("You did a bad, you said : " ++ show n)

 retrieveM :: ATree a -> Int -> Maybe a
 retrieveM (ALeaf x)     0 = Just x
 retrieveM (AFork l m r) n
   | m > n     = retrieveM l n
   | otherwise = retrieveM r (n - m)
 retrieveM _ n = Nothing
