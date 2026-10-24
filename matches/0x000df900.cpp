int Conv(int);
class C_df900 {
  public:
    char pad[0x600];
    int e[128];
    void F(int a, int b);
};
void C_df900::F(int a, int b) {
    // Find the first free slot (key == 0), scanning four entries per pass.
    int i = 0;
    int* p = (int*)((char*)this + 0x608);
    do {
        if (p[-2] == 0)
            break;
        if (p[0] == 0) {
            i = i + 1;
            break;
        }
        if (p[2] == 0) {
            i = i + 2;
            break;
        }
        if (p[4] == 0) {
            i = i + 3;
            break;
        }
        i = i + 4;
        p = p + 8;
    } while (i < 0x40);
    if (i < 0x40) {
        e[i * 2] = Conv(a);
        e[i * 2 + 1] = b;
    }
}
