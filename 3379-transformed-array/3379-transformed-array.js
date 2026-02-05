/**
 * @param {number[]} nums
 * @return {number[]}
 */
var constructTransformedArray = function (nums) {
    const n = nums.length;
    const res = new Array(n);
    for (let i = 0; i < n; i++) {
        const move = nums[i] % n;
        const j = (i + move + n) % n;
        res[i] = nums[j];
    }
    return res;

};