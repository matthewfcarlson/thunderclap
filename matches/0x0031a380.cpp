class Thing {
  public:
    int mVptr, mCopy;
    char p[0x30 - 8];
    int u, v;
    char p2[0x70 - 0x38];
    int a, b, c, d, e;
    char p3[4];
    int x[7];
    void Init(int, int, int, int, int);
};
void Thing::Init(int p1, int p2, int p3, int p4, int p5) {
    mCopy = mVptr;
    a = p1;
    b = p3;
    c = p2;
    d = p4;
    e = p5;
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    x[5] = 0;
    x[6] = 0;
    if ((p5 & 6) == 0)
        return;
    if (!(p5 & 4)) {
        u = 0x3f800000;
        v = 0;
        return;
    }
    if (p5 & 2)
        return;
    u = 0;
    v = 0x3f800000;
}