jay() {
    num=$1
    letter=$2
    ext=$3

    if [ "$num" -ge 1 ] && [ "$num" -le 500 ]; then
        folder="1-500"
    elif [ "$num" -ge 501 ] && [ "$num" -le 1000 ]; then
        folder="501-1000"
    elif [ "$num" -ge 1001 ] && [ "$num" -le 1500 ]; then
        folder="1001-1500"
    elif [ "$num" -ge 1501 ] && [ "$num" -le 2000 ]; then
        folder="1501-2000"
    elif [ "$num" -ge 2001 ] && [ "$num" -le 2500 ]; then
        folder="2001-2500"
    elif [ "$num" -ge 2501 ] && [ "$num" -le 3000 ]; then
        folder="2501-3000"
    elif [ "$num" -ge 3001 ] && [ "$num" -le 3500 ]; then
        folder="3001-3500"
    elif [ "$num" -ge 3501 ] && [ "$num" -le 4000 ]; then
        folder="3501-4000"
    elif [ "$num" -ge 4001 ] && [ "$num" -le 4500 ]; then
        folder="4001-4500"
    elif [ "$num" -ge 4501 ] && [ "$num" -le 5000 ]; then
        folder="4501-5000"
    else
        echo "Number out of range (1-5000)"
        return 1
    fi

    file="./$folder/${num}${letter}.${ext}"

    git add "$file"
    git commit -m "${num}${letter}"
    git push origin main
}