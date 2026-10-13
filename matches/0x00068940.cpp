class Obj {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m = v;
    return true;
}