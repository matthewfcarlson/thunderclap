class Entity_1d4d50 {
  public:
    Entity_1d4d50();
    virtual void G();
    char pad[0x90 - 4];
};
class M_1d4d50 {
  public:
    void Init();
    char q[8];
};
class CSPHulkProp : public Entity_1d4d50 {
  public:
    virtual void G();
    int a, b, c, d, e, f, g, h;
    unsigned char i, j, k, l, m, n, o;
    int p;
    char pad2[4];
    M_1d4d50 mm;
    CSPHulkProp();
};
CSPHulkProp::CSPHulkProp() {
    a = 0;
    b = 0;
    c = 0xffff;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 1;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;
    o = 0;
    p = 0;
    mm.Init();
}
