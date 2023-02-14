"use strict"

function alphabetPosition(text) {
    
    let resultString = '';
    text =  text.toLowerCase();

    for (let i = 0; i < text.length; i++) {

        if (text.charCodeAt(i) >= 97 && text.charCodeAt(i) <= 122) {
        resultString += text.charCodeAt(i) - 96 + ' ';
        }
    }

    return resultString.substring(0, resultString.length - 1);
}