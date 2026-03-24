main = do
  t <- readLn
  sequence_ [solve | _ <- [1..t]]

solve = do
  [x,y] <- fmap (map read . words) getLine
  if (x `div` 2 >= y && y >= (-x `div` 4)) && ((x + y) `mod` 3 == 0)
    then putStrLn "YES"
    else putStrLn "NO"