class Obj {
  public:
    char pad[12];
    int mValue;
    bool Set(int x);
};
bool Obj::Set(int x) {
    mValue = x;
    return true;
}
