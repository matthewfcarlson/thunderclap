struct Vec3_30d760 {
    int a, b, c;
};
class Target_30d760 {
    char pad0[0x14];
    int a0, a1, a2, b0, b1, b2;
    char pad1[0x58];
    char flag;
    char pad2[3];
    int enabled;
    int p0, p1, p2;

  public:
    void Set(Vec3_30d760* a, Vec3_30d760* b, int c, int d, int e);
};
void Target_30d760::Set(Vec3_30d760* a, Vec3_30d760* b, int c, int d, int e) {
    a0 = a->a;
    a1 = a->b;
    a2 = a->c;
    b0 = b->a;
    b1 = b->b;
    b2 = b->c;
    p0 = c;
    p1 = d;
    p2 = e;
    enabled = 1;
    flag = 0;
}