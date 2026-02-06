/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minRemoval = function (nums, k) {
    const n = nums.length;
    const arr = nums.map(BigInt);
    const K = BigInt(k);

    arr.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));

    function upperBound(target, lo, hi) {
        if (lo >= hi) return lo;
        const mid = lo + ((hi - lo) >> 1);

        if (arr[mid] <= target) {
            return upperBound(target, mid + 1, hi);
        } else {
            return upperBound(target, lo, mid);
        }
    }

    let best = 1;

    for (let i = 0; i < n; i++) {
        const target = arr[i] * K;
        const r = upperBound(target, i, n);
        const len = r - i;
        if (len > best) best = len;
    }
    return n - best;
};