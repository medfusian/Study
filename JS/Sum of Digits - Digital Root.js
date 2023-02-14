'use strict'

function digital_root(n) {

    n = String(n);
    let result = 0;

    for (let i = 0; i < n.length; i++) {
        
        result += +n[i]; 
    }
    if (result > 9) result = digital_root(result);

    return result;
}