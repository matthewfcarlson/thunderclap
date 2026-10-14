class Obj_5a200 {
  public:
    char pad[0x60];
    int mFoo;
    bool SetFoo(int value);
};
bool Obj_5a200::SetFoo(int value) {
    mFoo = value;
    return true;
}
