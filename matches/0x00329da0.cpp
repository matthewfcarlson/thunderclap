extern int gFlags;
extern int gA[32];
extern int gB[32];
class C {
    char pad[0x74];

  public:
    int a[16];
    int b[16];
    void F(int, int, int);
};
int gFlags;
int gA[32];
int gB[32];
void C::F(int i, int x, int y) {
    if (a[i] != x) {
        a[i] = x;
        gFlags |= 0x800;
        gA[i * 32] = x;
    }
    if (b[i] != y) {
        b[i] = y;
        gFlags |= 0x800;
        gB[i * 32] = y;
    }
}