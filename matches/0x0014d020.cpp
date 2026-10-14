class Obj {
  public:
    char pad[0x1c];
    int m;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m = v;
    return true;
}
