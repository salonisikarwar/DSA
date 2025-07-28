class Solution {
public:
   int xorFrom0To(int x) {
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

int xorOperation(int n, int start) {
    int x = start / 2;
    int r = start % 2;
    int xorVal = xorFrom0To(x + n - 1) ^ xorFrom0To(x - 1);
    return xorVal * 2 + (n % 2) * r;
}
};