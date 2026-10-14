class Obj_16fa70 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_16fa70::Set(int v) {
    mValue = v;
    return true;
}
