class Obj_139b80 {
  public:
    char pad[0x48];
    int mField;
    bool Set(int x);
};

bool Obj_139b80::Set(int x) {
    mField = x;
    return true;
}
