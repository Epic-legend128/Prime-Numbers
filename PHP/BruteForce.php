<?php
function isPrime($num) {
    if ($num <= 1) return false;
    if ($num == 2) return true;
    for ($i = 2; $i < $num; $i++) {
        if ($num%$i == 0) return false;
    }
    return true;
}

$num = 10;
echo "The number is ";
if (!isPrime($num)) echo "not ";
echo "prime.\n";
?>
