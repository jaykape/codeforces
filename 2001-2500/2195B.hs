import Control.Monad (replicateM_)
import Data.Bits (countTrailingZeros, shiftR)

main :: IO ()
main = do
  t <- readLn :: IO Int
  replicateM_ t solve

solve :: IO ()
solve = do
  n <- readLn  :: IO Int
  xs <- fmap (map read . words) getLine :: IO [Int]
  if check xs
    then putStrLn "YES"
    else putStrLn "NO"

oddPart :: Int -> Int
oddPart x = x `shiftR` countTrailingZeros x

check :: [Int] -> Bool
check xs =
  and [oddPart x == oddPart i | (i, x) <- zip [1..] xs]