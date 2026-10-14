class Obj_1238e0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_1238e0::Set(int v) {
    mValue = v;
    return true;
}