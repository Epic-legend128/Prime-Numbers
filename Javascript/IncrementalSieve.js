//incremental sieve
function incrementalSieve(upper) {
  let original = [2, 3];
  let primes = [[3, 3]];
  let isPrime;

  for (let i = 5; i<upper; i+=2) {
    isPrime = true;
    let right = Math.sqrt(i);
    for (let j = 0; j<primes.length; j++) {
      if (primes[j][0] > right) break;
      while (primes[j][1] < i) {
        primes[j][1] += primes[j][0];
      }
      if (primes[j][1] == i) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      primes.push([i, i]);
      original.push(i);
    }
    
  }
  return original;
}
