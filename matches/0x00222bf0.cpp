class A_222bf0 {
  public:
    char pad[0x68];
    unsigned count;
    int f(int key);
};
int A_222bf0::f(int key) {
    unsigned n = count;
    unsigned i = 0;
    if (n > 0) {
        int k = key;
        int* p = (int*)((char*)this + 0x6c);
        do {
            if (*p == k)
                return p[5];
            ++i;
            p += 10;
        } while (i < n);
    }
    return 0;
}