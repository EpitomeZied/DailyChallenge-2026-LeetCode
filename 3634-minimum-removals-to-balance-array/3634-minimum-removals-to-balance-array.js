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

  let best = 1;
  let l = 0;

  for (let r = 0; r < n; r++) {
    while (arr[r] > arr[l] * K) {
      l++;
    }
    best = Math.max(best, r - l + 1);
  }

  return n - best;
};