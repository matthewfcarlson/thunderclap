class Obj {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mVal = v;
    return true;
}
