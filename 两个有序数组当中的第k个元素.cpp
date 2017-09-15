
//计算两个有序数组的第K大的数
// 假设A B 两数组的元素都大于K/2，我们将A B两数组的第K/2个元素进行比较。比较的结果有三种情况。
// A[K/2] == B[K/2]
// A[K/2] > B[K/2]
// A[K/2] <= B[K/2]
// 如果 A[K/2] < B[K/2] 意味着 A[0] 到 A[K/2] 肯定在A∪B的前k个元素中。因此我们可以放心删除A数组的这个k/2个元素。同理A[K/2] > B[K/2]。
// 如果 A[K/2] == B[K/2] 说明已经找到了第K个元素，直接返回A[K/2]或者B[K/2]。
int find_kth (int a[], int m, int b[], int n, int k){
    if (m > n) {
        return find_kth(b, n, a, m, k);
    }
    if (m == 0) return b[k-1];
    if (k == 1) return min(a[0], b[0]);
    int ia = min(k/2, m);
    int ib = k-ia;
    if (a[ia - 1] < b[ib - 1]) {
        return find_kth(a + ia, m-ia, b, n, k - ia);
    } else if (a[ia - 1] > b[ib - 1]){
        return find_kth(a, m, b + ib, n - ib, k - ib);
    } else 
        return a[ia - 1];
}