class Obj {
  public:
    char pad[0x6c];
    int field;
    bool Set(int v);
};

bool Obj::Set(int v) {
    field = v;
    return true;
}
