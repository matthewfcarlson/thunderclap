struct V {
    int a;
    int b;
    int c;
};

class O {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    char Set(V* v);
};

char O::Set(V* v) {
    m24 = v->a;
    m28 = v->b;
    m2c = v->c;
    return 1;
}
