class Obj {
  public:
    bool Set(int v);
    char pad[0x0c];
    int mVal;
};
bool Obj::Set(int v) {
    mVal = v;
    return true;
}
