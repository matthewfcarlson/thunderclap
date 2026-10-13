class Obj {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m1c = x;
    return true;
}
