function gcd(a, b) {
    if(a<b) swap(a, b);
    if(a%b==0) return b;
    return gcd(b, a%b);
}

function power(base, exp, n) {
    var result = 1;
    base %= n;

    while (exp > 0) {
        if (exp & 1) result = (base*result)%n;
        exp>>=1;
        base=(base*base)%n;
    }
    return result;
}

function littleTheoremOfFermat(num) {
    if (num==3||num==2) return true;
    if (num<=1||num%2==0) return false;
    const CHECKS = 20;
    for (let i = 0; i<CHECKS; i++) {
        let current = Math.floor(Math.random()*(num-3)+2);
        if (gcd(num, current) != 1) return false;
        if (power(current, num-1, num) != 1) return false;
    }
    return true;
}

const test = 10; // number to check
console.log("The number "+test+" is "+(littleTheoremOfFermat(test)?"prime":"not prime"));
