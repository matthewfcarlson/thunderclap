struct M {
    int v;
};
class O {
    char p[0x10];
    M m;

  public:
    char Set(int x);
};
char O::Set(int x) {
    m.v = x;
    return 1;
}