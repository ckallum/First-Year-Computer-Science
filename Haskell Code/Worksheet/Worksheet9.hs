module Main where
import System.Environment
import System.Random
import ZipWith

main ::IO ()
main = do putStrLn "What is your difficulty"
          number <- getLine
          putStrLn "Guess a Number "
          game (read number)
          print(zipWith' (+)[1,2][1,2,3,4])

getInt :: IO Int
getInt = getLine>>=return.read

sayHello :: String->String
sayHello name = "Hello, " ++ name ++"!"

greet :: IO()
greet = getLine >>= putStrLn.sayHello

echoArgs::IO()
echoArgs = do args <- getArgs
              print args

unwords':: [String]->String
unwords' [] = ""
unwords' (x:xs) = x ++ unwords xs

echoArgs'::IO()
echoArgs' = do args <- getArgs
               putStrLn (unlines args)


addLineStart:: [String]->[String]
addLineStart = map (">" ++)

addLineStartToFile :: String-> String
addLineStartToFile = unlines.addLineStart.lines

hsToLhs::String->String->IO()
hsToLhs hs lhs = do contents<-(readFile hs)
                    writeFile lhs(addLineStartToFile contents)

playRound :: Int->IO()
playRound number =
  do
     guess <- getInt
     if guess == number then putStrLn "correct"
     else if guess<number then do putStrLn "too low"; playRound number
     else do putStrLn "too high"; playRound number

dice :: Int->IO Int
dice n = do i <- randomIO
            return(mod i n)

game :: Int->IO()
game difficulty = do number <- dice difficulty
                     playRound number
