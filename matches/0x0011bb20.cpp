class Obj_11bb20 {
  public:
    char pad[0x1c];
    int mValue;
    bool Set(int v);
};
bool Obj_11bb20::Set(int v) {
    mValue = v;
    return true;
}