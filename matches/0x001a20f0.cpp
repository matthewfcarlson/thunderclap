class Obj {
  public:
    char pad[12];
    int mField;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mField = v;
    return true;
}
