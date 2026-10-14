extern "C" char DAT_003f335c[];
class C_b0970 {
  public:
    struct E {
        int count;
        void* ptr;
    };
    char pad[0x2f8];
    E entries[6];
    void* f(int x, int y, int z);
};
void* C_b0970::f(int x, int y, int z) {
    if (x < 0 || x >= 2)
        return (void*)((int)DAT_003f335c);
    if (y < 0 || y >= 2)
        return (void*)((int)DAT_003f335c);
    if (z < 0 || z >= 3)
        return (void*)((int)DAT_003f335c);
    E* p = &entries[z + (y + x * 2) * 3];
    if (p->count <= 0)
        return (void*)((int)DAT_003f335c);
    return p->ptr;
}
