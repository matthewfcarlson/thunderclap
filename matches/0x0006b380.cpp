class Obj {
  public:
    char pad[0x44];
    int field;
    bool Set(int v);
};

bool Obj::Set(int v) {
    field = v;
    return true;
}
