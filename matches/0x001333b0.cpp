class Obj_1333b0 {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int x);
};

bool Obj_1333b0::Set(int x) {
    mValue = x;
    return true;
}