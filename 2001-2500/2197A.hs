import Control.Monad (replicateM_) 

main :: IO ()
main = do
    t <- readLn
    replicateM_ t runCase

runCase :: IO ()
runCase = do
    x <- readLn
    {- note that 
    1. if y is not end with 9
        then d(y+1) = d(y) + 1
        and thus y - d(y) are all equals from each X0 to X9. 
    2. y - d(y) strictly increase from y = X9 to y + 1 = Z0.

    so if x appears as some d(y) - y, the number of y's is 10.   
        -}
    

