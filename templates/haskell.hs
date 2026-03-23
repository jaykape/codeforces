import Control.Monad (replicateM_)

main = do
    t <- readLn
    replicateM_ t solve

solve = do
    -- logic