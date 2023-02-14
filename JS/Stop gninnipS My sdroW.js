'use strict'

function spinWords(string){

    let resultString = '',
        counter = 0;

    for (let i = 0; i < string.length; i++) {

        while (string[i] != ' ' && i < string.length) {
            
            i++;
            counter++;
        }
        if (counter < 5) {

            for (let k = i - counter; k != i; k++) {

                resultString += string[k];
            }
        }
        else {

            for (let k = i - 1; k != i - counter - 1; k--) {

                resultString += string[k];
            }
        }
        resultString += ' ';
        counter = 0;
    }
    return resultString.substring(0, resultString.length - 1); 
}