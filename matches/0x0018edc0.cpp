class Obj_18edc0 {
  public:
    char pad[0x40];
    int mValue;
    bool Set(int x);
};

bool Obj_18edc0::Set(int x) {
    mValue = x;
    return true;
}
