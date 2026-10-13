class Obj {
  public:
    char pad[0x10];
    int m10;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m10 = v;
    return true;
}
