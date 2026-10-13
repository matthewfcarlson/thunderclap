class Obj {
  public:
    char pad[0x40];
    int member;
    bool Set(int v);
};

bool Obj::Set(int v) {
    member = v;
    return true;
}
