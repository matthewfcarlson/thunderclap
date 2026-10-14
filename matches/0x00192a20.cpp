class Obj {
  public:
    char pad[0x68];
    int m68;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m68 = v;
    return true;
}
