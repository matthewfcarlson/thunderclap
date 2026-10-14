class Obj {
  public:
    char pad[0x1c];
    int mX;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mX = v;
    return true;
}
