class Obj {
  public:
    char pad[0xc4];
    int value;
    bool Set(int v);
};

bool Obj::Set(int v) {
    value = v;
    return true;
}
