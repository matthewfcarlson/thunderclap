typedef unsigned int u32;
void F339d70(void*, int, int);
int F3392c0(void*, int);
void F338fe0(void*, int, const char*);
void F213640(void*, int, int);
int FUN_0033e160(void* p, int ignored) {
    F339d70(p, 1, 5);
    int n = F3392c0(p, 1);
    F338fe0(p, n, "table too big to unpack");
    for (int i = 1; i <= n; ++i)
        F213640(p, 1, i);
    return n;
}