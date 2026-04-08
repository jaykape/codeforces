let input = '';
process.stdin.on('data', chunk => input += chunk);
process.stdin.on('end', () => {
    let lines = input.trim().split('\n');

    let t = parseInt(lines[0]);

    for (let i = 1; i <= t; i++) {
        let [l, r] = lines[i].split(' ').map(Number);

        if (2 * l <= r) {
            console.log(l, 2 * l);
        } else { console.log(-1, -1); }
    }

});

/*
If 2*l <= r we could pick lcm(l,2*l) = 2*l.
Else, 2*l > r assume that there is a solution x < y.
Case 1: x | y
meaning that y >= 2*x >= 2*l > r which is a ctd.
Case 2: x ~| y
So lcm(x,y) >= 2*y > 2*l > r, also a ctd.
*/