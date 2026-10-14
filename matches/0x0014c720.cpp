class Obj_14c720 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int x);
};

bool Obj_14c720::Set(int x) {
    mValue = x;
    return true;
}
