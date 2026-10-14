class Obj {
  public:
    char pad[0xc];
    int m1c;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m1c = v;
    return true;
}
