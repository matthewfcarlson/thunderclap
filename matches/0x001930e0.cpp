class Obj {
  public:
    char pad[0x5c];
    int value;
    bool Set(int v);
};

bool Obj::Set(int v) {
    value = v;
    return true;
}
