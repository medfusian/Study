"use strict"

alert ( longest("yjdht","fdrtkpwe") )

function longest(s1, s2) {
    
    let sumStr = (s1 + s2),
        resultStr = "",
        last = "";

    sumStr = sumStr.split('').sort().join('');
    let strLength = sumStr.length;

    for(let i = 0; i < strLength; i++){
    
        let char = sumStr.charAt(i);
        
        if (char !== last) {
            
            resultStr += char;
            last = char;
        
        }
    }

    return resultStr;
}