/* Copyright RedDevSoftware */

/**
 * Type Script Samples
 */


declare var x: number;


// 2D Matrix Summary
function sumMatrix(matrix: number[][]) {
    var sum = 0;
    var i = 0;

    for(; i < matrix.length; i++) {
        var currentRow = matrix[i];
        for(; i < currentRow.length; i++) {
            sum += currentRow[i];
        }
    }

    return sum;
}

var matrix = [[4,8,6],[1,7,6]];


sumMatrix(matrix); //summary matrix function

