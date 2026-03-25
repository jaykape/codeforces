import Control.Monad (replicateM_)
main = do
  t <- readLn
  replicateM_ t runCase

runCase = do
  [x,y] <- fmap (map read . words) getLine
  if (x `div` 2 >= y && y >= (-x `div` 4)) && ((x + y) `mod` 3 == 0)
    then putStrLn "YES"
    else putStrLn "NO"