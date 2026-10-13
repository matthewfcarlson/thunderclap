class Obj {
  public:
    char pad[0x60];
    int mFoo;
    bool SetFoo(int value);
};
bool Obj::SetFoo(int value) {
    mFoo = value;
    return true;
}
