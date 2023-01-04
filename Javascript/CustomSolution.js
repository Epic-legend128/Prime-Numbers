//relatively fast solution, O(n^(1/2)) time notation
function primalityTest(num) {
    if (num <= 1) return false;
    if (num%2==0) return num==2;
    for (let i = 3; i*i<=num; i+=2) {
        if (num%i==0) return false;
    }
    return true;
}

const test = 10; // number to check
console.log("The number "+test+" is "+(primalityTest(test)?"prime":"not prime"));
