class Obj {
  public:
    int m0;
    char pad[8];
    int m1;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m1 = v;
    return true;
}
