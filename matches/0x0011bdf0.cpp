class Obj_11bdf0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};
bool Obj_11bdf0::Set(int v) {
    mValue = v;
    return true;
}