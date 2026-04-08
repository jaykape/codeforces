let input = '';
process.stdin.on('data', chunk => input += chunk);
process.stdin.on('end', () => {
    let lines = input.trim().split('\n');
    let t = parseInt(lines[0]);

    for (let i = 1; i <= t; i++) {
        let x = parseInt(lines[i]);
        console.log(1, x - 1);

    }
});


/*
Let a = gA, b = gB where g = gcd(a, b).
Then gcd(a, b) + lcm(a, b) = g + gAB = g(AB + 1).

So for each x, we could pick a = 1, b = x - 1.
*/