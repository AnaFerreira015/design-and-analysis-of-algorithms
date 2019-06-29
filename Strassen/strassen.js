
function reduce(arrayMax, subArray, left, right) {
    for (var i = 0, i2 = left; i < subArray.length; i++ , i2++) {
        // var array = [];
        for (var j = 0, j2 = right; j < subArray.length; j++ , j2++) {
            arrayMax[i2][j2] = subArray[i][j];
        }
    }
}

/** Function only to declare array
 * - It receives a matrix and a dimension
 * - Initializes the array with 0's
 */
function declare(M, size) {
    for (i = 0; i < size; i++) {
        M[i] = [];
        for (var j = 0; j < size; j++) {
            M[i][j] = 1;
        }
    }
}

/** - Adds matrix A to matrix A and matrix B to matrix C 
 * - Receives two arrays
 * - Creates a new array with the subtraction of past arrays
*/
function sub(A, B) {
    // console.log(A.length + " " + A[0].length);
    // console.log(B.length + " " + B[0].length);
    var C = [];
    for (i = 0; i < A.length; i++) {
        var array = [];
        for (j = 0; j < A[0].length; j++) {
            array.push(A[i][j] - B[i][j]);
        }
        C.push(array);
    }
    return C;
}

/** - Adds matrix A to matrix A and matrix B to matrix C
 * - Receives two arrays
 * - Creates a new array with the sum of the passed arrays
*/
function add(A, B) {
    var C = [];
    for (var i = 0; i < A.length; i++) {
        var array = [];
        for (var j = 0; j < A[0].length; j++) {
            array.push(A[i][j] + B[i][j]);
        }
        C.push(array);
    }
    return C;
}

/** - It receives the matrix A or B
 * - left is the position that will start the mapping
 * - right is the final position of the mapping
 * - quadrant is to be able to perform the method of dividing and conquering in each matrix
 * - Returns an array mapped according to the passed array
 */
function map(arrayMax, left, right, quadrant) {
    var subArray = [];
    for (var i = 0, i2 = left; i < quadrant; i++ , i2++) {
        var array = [];
        for (var j = 0, j2 = right; j < quadrant; j++ , j2++) {
            array.push(arrayMax[i2][j2]);
        }
        subArray.push(array);
    }
    return subArray;
}

/** Calculate the strassen */
function strassen(A, B) {
    //console.log(A);
    // console.log(B);
    // console.log("^ AB ^");
    var size = A.length;
    // var C = [];
    var C = new Array(A.length);
    for (var i = 0; i < C.length; i++)
        C[i] = new Array(B[0].length);

    //declare(C, size);

    // console.log("matriz C");
    //console.log(C);
    if (size % 2 != 0 && size != 1) {
        var a1 = [];
        var b1 = [];
        var c1 = [];

        var size2 = size + 1;

        declare(a1, size2);
        declare(b1, size2);
        declare(c1, size2);

        for (var i = 0; i < size; i++) {
            for (var j = 0; j < size; j++) {
                a1[i][j] = A[i][j];
                b1[i][j] = B[i][j];
            }
        }
        c1 = strassen(a1, b1);
        for (var i = 0; i < size; i++) {
            for (var j = 0; j < size; j++) {
                C[i][j] = c1[i][j];
            }
        }
        return C;
    }
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        // return A[0] * B[0];
    }
    else {
        var A11, A12, A22, A21, B11, B12, B22, B21 = [];

        A11 = map(A, 0, 0, size / 2);
        A12 = map(A, size / 2, 0, size / 2);
        A21 = map(A, 0, size / 2, size / 2);
        A22 = map(A, size / 2, size / 2, size / 2);

        B11 = map(B, 0, 0, size / 2);
        B12 = map(B, size / 2, 0, size / 2);
        // console.log(B12);
        // console.log("B12 ^");
        B21 = map(B, 0, size / 2, size / 2);
        B22 = map(B, size / 2, size / 2, size / 2);
        // console.log(B22);
        // console.log("B22 ^");
        // console.log(sub(B12, B22));
        // console.log("sub B12, B22");

        var M1 = strassen(add(A11, A22), add(B11, B22));
        var M2 = strassen(add(A21, A22), B11);
        var M3 = strassen(A11, sub(B12, B22));
//        console.log("M3", M3);
        var M4 = strassen(A22, sub(B21, B11));
        var M5 = strassen(add(A11, A12), B22);
        var M6 = strassen(sub(A21, A11), add(B11, B12));
        var M7 = strassen(sub(A12, A22), add(B21, B22));

        var C11 = add(sub(add(M1, M4), M5), M7);
        var C12 = add(M3, M5);
        var C21 = add(M2, M4);
        var C22 = add(sub(add(M1, M3), M2), M6);

        reduce(C, C11, 0, 0);
        reduce(C, C12, size / 2, 0);
        reduce(C, C21, 0, size / 2);
        reduce(C, C22, size / 2, size / 2);
    }
    return C;
}