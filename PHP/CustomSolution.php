<?php
function primalityTest($num) {
    if ($num <= 1) return false;
    if ($num%2 == 0) return $num==2;
    for ($i = 3; $i*$i<=$num; $i+=2) {
        if ($num%$i == 0) return false;
    }
    return true;
}

$num = 10;
echo "The number is ";
if (!primalityTest($num)) echo "not ";
echo "prime.\n";
?>
