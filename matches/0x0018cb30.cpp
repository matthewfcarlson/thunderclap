class Obj {
    char pad[0x18];
    int m18;

  public:
    bool Set(int x);
};

bool Obj::Set(int x) {
    m18 = x;
    return true;
}
