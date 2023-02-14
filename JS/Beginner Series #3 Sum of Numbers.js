"use strict";

function getSum( a, b )
{
    let sum = 0;

    if (a==b) return a;

    if (a < b) {    
        for (let i = a; i <= b; i++) {
            sum += i;
        }
        return sum;
    }

    for (let i = b; i <= a; i++) {
        sum += i;
    }
    return sum;
}