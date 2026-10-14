class X_c8190 {
  public:
    char pad[0x258];
    int vals[128][16];
    int* f(int i);
};
int* X_c8190::f(int i) {
    if (i < 0 || i >= 128)
        return 0;
    int* p = (int*)((char*)this + 0x258 + i * 64);
    return (int*)((unsigned)p & ((*p == -1) - 1));
}