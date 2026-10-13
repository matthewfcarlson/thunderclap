class Obj {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m1c = v;
    return true;
}