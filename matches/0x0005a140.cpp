struct V {
    int a;
    int b;
    int c;
};

class O_5a140 {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    char Set(V* v);
};

char O_5a140::Set(V* v) {
    m24 = v->a;
    m28 = v->b;
    m2c = v->c;
    return 1;
}
