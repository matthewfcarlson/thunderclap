extern int a, b, c;
struct ThisWrap_000e74a0 {
    int inner(int);
    int target(int x);
};
int __cdecl outer(int, int, int*, int*, int);
int ThisWrap_000e74a0::target(int x) {
    return outer(outer(this->inner(x), 0, &c, &b, 0), 0, &b, &a, 0);
}