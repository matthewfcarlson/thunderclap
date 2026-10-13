class Obj {
  public:
    char pad[0x5c];
    int m5c;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m5c = v;
    return true;
}
