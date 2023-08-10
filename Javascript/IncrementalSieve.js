//incremental sieve
function incrementalSieve(upper) {
  let primes = [2, 3];
  let isPrime;

  for (let i = 5; i<upper; i+=2) {
    isPrime = true;
    for (let j = 0; j<primes.length-1; j++) {
      if (i%primes[j] == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push(i);
    }
  }
  
  return primes;
}
