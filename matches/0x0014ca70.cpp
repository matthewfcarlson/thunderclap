class Obj {
  public:
    char pad[0x4c];
    int m4c;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m4c = v;
    return true;
}
