class Obj_1aad30 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};

bool Obj_1aad30::Set(int v) {
    mValue = v;
    return true;
}
