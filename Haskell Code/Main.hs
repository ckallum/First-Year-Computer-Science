module Main where

import Prelude hiding (lookup)
-- import Trie
import System.Environment

main :: IO ()
main = do putStrLn "The awesome word counting machine"
--           [filePath] <- getArgs
--           file <- readFile filePath
--           let trie = makeTrie (words file)
--           enquire trie
--
--
-- enquire :: Trie Char Integer -> IO ()
-- enquire trie = do
--   putStrLn "What do you want to know?"
--   word <- getLine
--   let mx - lookup word trie
--   putStrLn ("The word appears" ++ show mx ++ "times")
--
--
-- count :: String -> String -> Int
-- count file word = count' (words file) word 0
--
-- count' :: [String] -> String -> Int -> Int
-- count' [] word n = newtype
-- count' (x:xs) word n = Other
--
--
--
-- makeTrie :: [String] -> Trie Char Integer
-- makeTrie ws = foldr f k ws where
--   k :: Trie Char Integer
--   k = empty
--
--   f :: [Char]-> Trie Char Integer -> Trie Char Integer
--   f w trie = adjust w incr trie
--
-- incr :: Maybe Integer -> Maybe Integer
-- incr Nothing = Just 1
-- incr (Just n) = Just (n + 1)
