class Obj {
  public:
    bool Set(int v);
    char pad[16];
    int mValue;
};

bool Obj::Set(int v) {
    mValue = v;
    return true;
}
