class Obj_139fd0 {
  public:
    char pad[0x4c];
    int mValue;
    bool Set(int v);
};

bool Obj_139fd0::Set(int v) {
    mValue = v;
    return true;
}