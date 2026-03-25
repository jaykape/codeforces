import Control.Monad (replicateM_) 

main :: IO ()
main = do
    t <- readLn
    replicateM_ t runCase

digitSum :: Int -> Int
digitSum = sum . map (read . (:[])) . show

runCase :: IO ()
runCase = do
    x <- readLn

    {- note that 
    1. if y is not end with 9
        then d(y+1) = d(y) + 1
        and thus y - d(y) are all equals from each X0 to X9. 
    2. y - d(y) strictly increase from y = X9 to y + 1 = Z0.

    so if x appears as some y - d(y), the number of y's is 10.   

    also, for y = a_n * 10^n + ... + a_1 * 10^1 + a_0
    y - d(y) = a_n * (10^n - 1) + ... + a_1 * (10^1 - 1)
    is divisible by 9, so we could eliminate x when x % 9 != 0
        -}
    
    if x `mod` 9 /= 0
        then print 0
        else print (if existsY x then 10 else 0)
    
existsY :: Int -> Bool
existsY x = go x 
    where
        go y
            | val == x = True
            | val > x = False
            | otherwise = go (y + 10)
            where
                val = y - digitSum y
    

