class Obj_139ec0 {
  public:
    char pad[0x24];
    int mField;
    bool Set(int v);
};

bool Obj_139ec0::Set(int v) {
    mField = v;
    return true;
}