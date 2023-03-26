<?php
function sieveOfEratosthenes($lower, $upper) {
    $is_prime = array_fill(0, $upper+1, true);
    $is_prime[0] = false;
    $is_prime[1] = false;
    $primes = [];
    for ($i = 2; $i <= $upper; $i++) {
        if ($is_prime[$i] == true) {
            for ($j = $i*$i; $j<=$upper; $j+=$i) {
                $is_prime[$j] = false;
            }
            if ($i>=$lower) array_push($primes, $i);
        }
    }
    return $primes;
}

$lower = 1;
$upper = 10;
$primes = sieveOfEratosthenes($lower, $upper);
if (count($primes) > 0) {
    echo $primes[0];
    for ($i = 1; $i<count($primes); $i++) {
        echo ", ";
        echo $primes[$i];
    }
}
else {
    echo "There are no prime numbers within the given range";
}
?>
