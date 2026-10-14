class Obj {
  public:
    bool Set(int v);
    char pad[24];
    int mValue;
};

bool Obj::Set(int v) {
    mValue = v;
    return true;
}
