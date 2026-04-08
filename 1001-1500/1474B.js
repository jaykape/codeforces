let input = '';
process.stdin.on('data', chunk => input += chunk);
process.stdin.on('end', () => {
    const lines = input.trim().split('\n');
    const t = parseInt(lines[0]);

    for (let i = 1; i <= t; i++) {
        const d = parseInt(lines[i]);
        
        const p = nextPrime(d);
        const q = nextPrime(p + d - 1);
        console.log(p * q);
    }

});

function isPrime(x) {
    if (x < 2) return false;
    if (x % 2 === 0) return x === 2;
    if (x % 3 === 0) return x === 3;

    for (let i = 5; i * i <= x; i += 6) {
        if (x % i === 0 || x % (i + 2) === 0) return false;
    }
    return true;
}

function nextPrime(n) {
    let x = n + 1
    
    if (x <= 2) return 2;
    if (x % 2 === 0) x++;

    while (!isPrime(x)) x += 2;

    return x;

}

/**
 * Let a be the solution and p be its smallest prime divisor.
 * We have that p - 1 >= d.
 * If a has no other prime divisor, then it took at least a = p^3 to has >= 4 divisors.
 * If a has another divisor q > p, then a = pq has 4 divisors.
 * 
 * Note that if q is the smallest prime with q - p >= d,
 * then q < 2(p + d) (Bertrand's postulate), thus pq < 2p(p+d) < 4p^2 <= p^3.
 * Note that for edge cases d < 4 we checked concretely that it's worked.
 * 
 * So we just have to find the smallest primes p > d and q > p + d - 1 for each d and return p*q.
 */