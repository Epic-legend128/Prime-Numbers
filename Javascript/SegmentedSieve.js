//sieve of eratosthenes
function sieve(upper) {
  var isPrime = [];
  for (let i = 0; i<=upper; i++) isPrime.push(true);
  isPrime[0] = false;
  isPrime[1] = false;
  var primes = [2];
  for(let i = 3; i<=upper; i+=2) {
      if (isPrime[i]) {
          primes.push(i);
          for (let j = i*i; j<=upper; j+=i) {
              isPrime[j] = false;
          }
      }
  }
  return primes;
} 

//segmented sieve
function segmentedSieve(limit) {
  const increment = Math.floor(Math.sqrt(limit))+1;
  var primes = sieve(increment);
  let n = primes.length;

  var low = increment;
  var high = increment*2;
  
  let pm;

  while (low < limit) {
    if (high > limit) {
      high = limit;
    }

    var isPrime = new Array(high-low+1).fill(true);
    for (let j = 0; j<n; j++) {
      pm = primes[j];
      let l = Math.floor(low/pm)*pm;
      if (l < low) l += pm;

      for (let k = l; k<high; k+=pm) {
        isPrime[k-low] = false;
      }
    }

    for (let i = low; i<high; i++) {
      if (isPrime[i-low]) {
        primes.push(i);
      }
    }

    low = high;
    high += increment;
  }

  return primes;
}
