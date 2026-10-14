class Obj {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};
bool Obj::Set(int v) {
    mValue = v;
    return true;
}