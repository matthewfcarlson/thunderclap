class Obj_6b3a0 {
  public:
    char pad[0x48];
    int mValue;
    bool Set(int v);
};

bool Obj_6b3a0::Set(int v) {
    mValue = v;
    return true;
}