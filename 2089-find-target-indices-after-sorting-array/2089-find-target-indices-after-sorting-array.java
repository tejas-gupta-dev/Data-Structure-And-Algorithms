class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        Arrays.sort(nums);
        int lo = 0, hi = nums.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        List<Integer> res = new ArrayList<>();
        while (lo < nums.length && nums[lo] == target) {
            res.add(lo++);
        }
        return res;
    }
}