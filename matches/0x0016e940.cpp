class Obj {
  public:
    char pad[0x58];
    int field;
    bool Set(int x);
};

bool Obj::Set(int x) {
    field = x;
    return true;
}
