class Obj_6b350 {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int x);
};
bool Obj_6b350::Set(int x) {
    mValue = x;
    return true;
}
