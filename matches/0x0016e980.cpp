class Obj {
  public:
    char pad[0x60];
    int m60;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m60 = v;
    return true;
}
