class Obj_193610 {
  public:
    char pad[0x10c];
    int mValue;
    bool Set(int x);
};

bool Obj_193610::Set(int x) {
    mValue = x;
    return true;
}
