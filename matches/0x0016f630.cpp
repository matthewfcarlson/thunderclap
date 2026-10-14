class Obj_16f630 {
  public:
    char pad[0x18];
    int m18;
    bool Set(int v);
};

bool Obj_16f630::Set(int v) {
    m18 = v;
    return true;
}
