/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function (n) {
    const x = n ^ (n >> 1);
    return (x & (x + 1)) === 0;

};