extern int DAT_0039db08;
extern int DAT_0039db50[32];
extern int DAT_0039db58[32];
class C_329da0 {
    char pad[0x74];

  public:
    int a[16];
    int b[16];
    void F(int, int, int);
};
int DAT_0039db08;
int DAT_0039db50[32];
int DAT_0039db58[32];
void C_329da0::F(int i, int x, int y) {
    if (a[i] != x) {
        a[i] = x;
        DAT_0039db08 |= 0x800;
        DAT_0039db50[i * 32] = x;
    }
    if (b[i] != y) {
        b[i] = y;
        DAT_0039db08 |= 0x800;
        DAT_0039db58[i * 32] = y;
    }
}