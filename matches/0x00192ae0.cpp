class Obj {
  public:
    char pad[0x98];
    int m98;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m98 = x;
    return true;
}