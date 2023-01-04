//brute force, O(n) time notation
function isPrime(num) {
    if (num <= 1) return false;
    if (num==2) return true;
    for (let i = 2; i<num; i++) {
        if (num%i==0) return false;
    }
    return true;
}

const test = 10; // number to check
console.log("The number "+test+" is "+(isPrime(test)?"prime":"not prime"));
