class Obj {
  public:
    char pad[0x7c];
    int m7c;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m7c = x;
    return true;
}
