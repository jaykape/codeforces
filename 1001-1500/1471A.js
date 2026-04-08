let input = '';
process.stdin.on('data', chunk => input += chunk);
process.stdin.on('end', () => {
    const lines = input.trim().split('\n');
    const t = parseInt(lines[0]);

    for (let i = 1; i <= t; i++) {
        const [n, x] = lines[2 * i - 1].split(' ').map(Number);
        const a = lines[2 * i].split(' ').map(Number);
        let count = 0;
        const sum = a.reduce((acc, cur) => acc + cur, 0);
        const quotSum = a.reduce((acc, cur) => acc + Math.floor(cur/x), 0);
        for (let j = 0; j < n; j++) {
            if (a[j] % x != 0) { count += 1; }
        }
        console.log(Math.floor(sum/x) + (sum % x == 0 ? 0 : 1), quotSum + count);
    }
});


/**
 * For each operation of replacing u, v with u + v,
 * there are following scenario:
 * 1. Both u and v are divisible by x, then the beauty remain the same.
 * 2. One of them is not divisible by x, then both before and after we got only extra +1.  
 * 3. Two of them is not divisible by x, before we get +2 extra from them and after at best we will get +1.
 * 
 * That is the maximum beauty will be obtained by performing no operation.
 * 
 * Note that the minimum is at most normal sum + 1, since we could sum all elements in the array into one element.
 * Lower minimum meaning that we could partition them so each of its sum is divisible by x.
 * But that's just simply mean the sum is divisible by x anyway.
 * 
 * That is 
 * max = sum of each floor + (number of element not divisible by x)
 * min = floor(sum/x) + (sum % x == 0 ? 0 : 1)
 */