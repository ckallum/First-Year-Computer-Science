module HelloWorld where

  main::IO()
  main = print(fibList 10)

  fib :: Int->Int
  fib 0 = 1
  fib 1 = 1
  fib n = fib(n-1) + fib(n-2)
  fibList n = map fib[1..n]
