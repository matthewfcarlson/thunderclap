class Obj {
  public:
    char pad[0x1c];
    int field;
    bool f(int x);
};

bool Obj::f(int x) {
    field = x;
    return true;
}
