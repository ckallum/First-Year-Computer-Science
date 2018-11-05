main = print (qsort [45,6,7,8,9])
-- Insertion sort

-- insert :: Ord a => a -> [a] -> [a]
insert :: Int -> [Int] -> [Int]
insert x []     = [x]
insert x (y:ys)
  | x < y     = x : y : ys
  | otherwise = y : insert x ys

{-
sort :: [Int] -> [Int]
sort xs = foldr f k xs where
  f :: Int -> [Int] -> [Int]
  f x ys = insert x ys

  k :: [Int]
  k = []
-}

isort :: [Int] -> [Int]
isort xs = sort' xs []
  where
    sort' :: [Int] -> [Int] -> [Int]
    sort' [] ys     = ys
    sort' (x:xs) ys =
      sort' xs ys'
      where
        ys' = insert x ys

-- Quick sort

qsort :: [Int] -> [Int]
qsort []     = []
qsort [x]    = [x]
qsort (x:xs) = ls ++ [x] ++ rs
  where ls = qsort (smallers x xs)
        rs = qsort (biggers x xs)

smallers :: Int -> [Int] -> [Int]
smallers x [] = []
smallers x (y:ys)
  | y <= x     = y : smallers x ys
  | otherwise = smallers x ys

biggers :: Int -> [Int] -> [Int]
biggers x [] = []
biggers x (y:ys)
  | y > x     = y : biggers x ys
  | otherwise = biggers x ys


split :: [a] -> ([a], [a])
split xs = (ys, zs) where
  ys = take n xs
  zs = drop n xs
  n  = length xs `div` 2


split' :: [a] -> ([a], [a])
split' []     = ([], [])
split' (x:xs) = (x:ys, zs)
  where
    (zs, ys) = split' xs



-- Merge sort

msort :: [Int] -> [Int]
msort [] = []
msort [x] = [x]
msort xs = merge ys' zs'
  where (ys, zs) = split' xs
        ys' = msort ys
        zs' = msort zs

merge :: [Int] -> [Int] -> [Int]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
  | x < y     = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys
