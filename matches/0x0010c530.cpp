class Obj_10c530 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_10c530::Set(int v) {
    mValue = v;
    return true;
}
