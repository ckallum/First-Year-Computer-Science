zipWith'::(a->b->c)->[a]->[b]->[c]
zipWith' f [] ys = []
zipWith' f xs [] = []
zipWith' f (x:xs) (y:ys) = (f x y) : (zipWith' f xs ys)

-- snoc'::[a] -> a ->[a]
-- snoc' xs x = xs ++ [x]
--
-- -- reverse' :: [a] -> [a]
-- -- reverse
