class Obj {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mValue = v;
    return true;
}