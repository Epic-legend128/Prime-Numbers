function sieveOfEratosthenes(lower, upper) {
    var isPrime = [];
    for (let i = 0; i<=upper; i++) isPrime.push(true);
    isPrime[0] = false;
    isPrime[1] = false;
    var primes = [];
    for(let i = 2; i<=upper; i++) {
        if (isPrime[i]) {
            if (i >= lower) primes.push(i);
            for (let j = i*i; j<=upper; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

const lower = 0;
const upper = 10;
const primes = sieveOfEratosthenes(lower, upper);
console.log(primes.join(", "));
