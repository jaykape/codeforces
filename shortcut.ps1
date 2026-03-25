function jay {
    param (
        [int]$num,
        [string]$letter,
        [string]$ext
    )

    switch ($num) {
        {$_ -ge 1 -and $_ -le 500}   { $folder = "1-500"; break }
        {$_ -ge 501 -and $_ -le 1000} { $folder = "501-1000"; break }
        {$_ -ge 1001 -and $_ -le 1500} { $folder = "1001-1500"; break }
        {$_ -ge 1501 -and $_ -le 2000} { $folder = "1501-2000"; break }
        {$_ -ge 2001 -and $_ -le 2500} { $folder = "2001-2500"; break }
        {$_ -ge 2501 -and $_ -le 3000} { $folder = "2501-3000"; break }
        default { Write-Host "Number out of range"; return }
    }

    $file = ".\$folder\$num$letter.$ext"

    git add $file
    git commit -m "$num$letter"
    git push origin main
}

<# Use case 
   jay 1234 A cpp
   
   Result
   git add ".\1001-1500\1234A.cpp"
   git commit -m "1234A"
   git push origin main
 #>