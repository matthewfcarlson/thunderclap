struct Triple {
    int a, b, c;
};
class Target {
  public:
    char pad[0x5c];
    int x, y, z;
    char pad2[8];
    int value;
    unsigned char flag;
    void Set(Triple* p, int v, unsigned char f);
};
void Target::Set(Triple* p, int v, unsigned char f) {
    x = p->a;
    y = p->b;
    z = p->c;
    value = v;
    flag = f;
}