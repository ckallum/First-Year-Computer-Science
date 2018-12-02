module Main where

import Prelude hiding (lookup)
import System.Environment
import Trie
import Data.Char

main :: IO ()
main = do putStrLn "The awesome word counting machine"
          [filePath] <- getArgs
          file <- readFile filePath
          let trie = makeTrie (words (map toLower file))
          enquire trie

enquire :: Trie Char Integer -> IO ()
enquire trie = do
  putStrLn "What do you want to know, foolish human?"
  word <- getLine
  let mx = lookup word trie
  putStrLn ("The word appears " ++ show mx ++ " times, oh foolish one.")
  enquire trie

makeTrie :: [String] -> Trie Char Integer
makeTrie ws = foldr f k ws where
  k :: Trie Char Integer
  k = empty

  f :: [Char] -> Trie Char Integer -> Trie Char Integer
  f w trie = adjust w incr trie

incr :: Maybe Integer -> Maybe Integer
incr Nothing  = Just 1
incr (Just n) = Just (n + 1)


count :: String -> String -> Int
count file word = count' (words file) word 0

count' :: [String] -> String -> Int -> Int
count' []     word n = n
count' (x:xs) word n
  | x == word = count' xs word (n+1)
  | otherwise = count' xs word n




