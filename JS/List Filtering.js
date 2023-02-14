"use strict"

function filter_list(l) {

    let resultString = [];

    for (let i = 0; i < l.length; i++) {
        
        if (typeof( l[i] ) == 'number') {
            
            resultString.push( l[i] );
        
        }
    }

    return resultString;
}