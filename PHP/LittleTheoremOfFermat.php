<?php
function gcd($a, $b) {
    if ($a < $b) return gcd($b, $a);
    if ($a%$b == 0) return $b;
    return gcd($b, $a%$b);
}

function power($base, $exp, $n) {
    $result = 1;
    $base %= $n;

    while ($exp > 0) {
        if ($exp & 1) $result = ($result*$base)%$n;
        $exp>>=1;
        $base=($base*$base)%$n;
    }
    return $result;
}

function littleTheoremOfFermat($num) {
    if ($num==3||$num==2) return true;
    if ($num%2==0||$num==1) return false;

    $checks = $num > 20 ? 20 : $num;
    for ($i = 0; $i<$checks; $i++) {
        $current = rand(2, $num-2);
        if (gcd($num, $current) != 1) return false;
        if (power($current, $num-1, $num) != 1) return false;
    }
    return true;
}

$num = 10;
echo "The number is ";
if (!littleTheoremOfFermat($num)) echo "not ";
echo "prime.\n";
?>
