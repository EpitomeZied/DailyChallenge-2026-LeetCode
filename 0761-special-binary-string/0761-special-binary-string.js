/**
 * @param {string} s
 * @return {string}
 */
var makeLargestSpecial = function (s) {
    let parts = [];
    let balance = 0;
    let start = 0;

    for (let i = 0; i < s.length; i++) {
        balance += (s[i] === '1') ? 1 : -1;

        if (balance === 0) {
            const inner = s.slice(start + 1, i);
            const bestInner = makeLargestSpecial(inner);
            parts.push('1' + bestInner + '0');
            start = i + 1;
        }
    }

    parts.sort((a, b) => (a < b ? 1 : (a > b ? -1 : 0)));
    return parts.join('');
};