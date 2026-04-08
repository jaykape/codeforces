let input = '';
process.stdin.on('data', chunk => input += chunk);
process.stdin.on('end', () => {
    let lines = input.trim().split('\n');
    let t = parseInt(lines[0]);

    for (let i = 1; i <= t; i++) {
        let n = parseInt(lines[i]);
        if (n == 36 || n == 40 || n == 44) {
            console.log('YES');
            console.log(6, 10, 15, n - 31);
        }
        else if (n >= 31) {
            console.log('YES');
            console.log(6, 10, 14, n - 30)
        }
        else { console.log('NO'); }
    }
});


/*
The smallest nearly primes are 6, 10, 14.
The sum = 30. So n must be greater than 30.

Note that any n >= 31 could represent by 30 + (n - 30),
since there is no constraint on the other element.

Note that there is an edge cases when n - 30 = 6, 10, 14,
i.e. n = 36, 40, 44. 
Other nearly primes available are 15, 
We will handle it concretely with
36 = 6 + 10 + 15 + 5
40 = 6 + 10 + 15 + 9
44 = 6 + 10 + 15 + 13 
*/