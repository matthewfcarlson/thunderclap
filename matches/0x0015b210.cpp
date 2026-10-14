class Obj {
  public:
    char pad[0xa8];
    int mValue;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mValue = v;
    return true;
}