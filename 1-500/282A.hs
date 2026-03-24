import Control.Monad (replicateM)

main = do
    n <- readLn
    xs <-  replicateM n getLine
    let result = sum (map convert xs)
    print result

convert :: String -> Int
convert s =
    if '+' `elem` s then 1 else -1

    

