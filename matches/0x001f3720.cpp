struct Pair_1f3720 {
    int a;
    int b;
};
class Target_1f3720 {
  public:
    char pad[8];
    int x;
    int y;
    int z;
    int w;
    unsigned char q;
    void Init(int, int);
    void Set(Pair_1f3720*, int, int, int, int, unsigned char);
};
void Target_1f3720::Set(Pair_1f3720* p, int a, int b, int c, int d, unsigned char e) {
    Init(p->a, p->b);
    x = a;
    y = b;
    z = c;
    w = d;
    q = e;
}