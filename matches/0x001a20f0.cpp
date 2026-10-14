class Obj_1a20f0 {
  public:
    char pad[12];
    int mField;
    bool Set(int v);
};

bool Obj_1a20f0::Set(int v) {
    mField = v;
    return true;
}
