import Data.Maybe

data ATree a = ALeaf a
            | AFork (ATree a) Int (ATree a)
     deriving Show --this automatically makes a Show instance--

--The following could be used to manually define a show instance
  --instance Show a => Show (ATree a) where
    --show(ALeaf x) = "<" ++ show x ++ ">"

flatten :: ATree a -> [a]
flatten (ALeaf x) = [x]
flatten (AFork l ix r) = flatten l ++ flatten r

mkATree :: [a] -> ATree a
mkATree [] = "Error"
mkATree [x] = ALeaf x
mkAtree xs = AFork l ix r
    where (ls,rs) = splitAt (n 'div' 2) xs
          n = length xs
          l = mkATree ls
          ix = length ls
          r = mkATree rs

retrieveM :: ATree a -> Int -> Maybe a
retrieveM (ALeaf x) 0 = Just x
retrieveM (AFork l m r) n
  | m > n = retrieveM l (n)
  | otherwise = retrieveM r (n-m)
retrieve _ _ = Nothing
