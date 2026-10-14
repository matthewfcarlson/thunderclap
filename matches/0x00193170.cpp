class Obj {
  public:
    char pad[0x6c];
    int m6c;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m6c = v;
    return true;
}
