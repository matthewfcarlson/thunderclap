class Obj {
  public:
    char pad[0x30];
    int m30;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m30 = x;
    return true;
}
