class Obj {
  public:
    char pad[12];
    int field;
    bool Set(int x);
};

bool Obj::Set(int x) {
    field = x;
    return true;
}
