struct M_61fa0 {
    int v;
};
class O_61fa0 {
    char p[0x10];
    M_61fa0 m;

  public:
    char Set(int x);
};
char O_61fa0::Set(int x) {
    m.v = x;
    return 1;
}