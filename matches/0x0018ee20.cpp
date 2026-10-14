class Obj_18ee20 {
  public:
    char pad[0x14];
    int mValue;
    bool Set(int v);
};
bool Obj_18ee20::Set(int v) {
    mValue = v;
    return true;
}
