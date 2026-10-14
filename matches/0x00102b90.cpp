struct Triple_102b90 {
    int a, b, c;
};
class Target_102b90 {
  public:
    char pad[0x5c];
    int x, y, z;
    char pad2[8];
    int value;
    unsigned char flag;
    void Set(Triple_102b90* p, int v, unsigned char f);
};
void Target_102b90::Set(Triple_102b90* p, int v, unsigned char f) {
    x = p->a;
    y = p->b;
    z = p->c;
    value = v;
    flag = f;
}