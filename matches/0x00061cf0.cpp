struct V {
    int a;
    int b;
    int c;
};
class T_61cf0 {
  public:
    char f(V* v);
    char pad[0x2c];
    int x2c;
    int x30;
    int x34;
};
char T_61cf0::f(V* v) {
    x2c = v->a;
    x30 = v->b;
    x34 = v->c;
    return 1;
}
