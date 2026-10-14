extern int gFlags_329da0;
extern int gA_329da0[32];
extern int gB_329da0[32];
class C_329da0 {
    char pad[0x74];

  public:
    int a[16];
    int b[16];
    void F(int, int, int);
};
int gFlags_329da0;
int gA_329da0[32];
int gB_329da0[32];
void C_329da0::F(int i, int x, int y) {
    if (a[i] != x) {
        a[i] = x;
        gFlags_329da0 |= 0x800;
        gA_329da0[i * 32] = x;
    }
    if (b[i] != y) {
        b[i] = y;
        gFlags_329da0 |= 0x800;
        gB_329da0[i * 32] = y;
    }
}