"use strict"

function accum(s) {

    let resultString = '';
    s = s.toLowerCase();
    
    for (let i = 0; i < s.length; i ++) {

        resultString += s[i].toUpperCase();
        
        for (let k = 0; k < i; k++) {
            resultString += s[i];
        }

        resultString += '-';
    }
    
    return resultString.substring(0, resultString.length - 1);
}