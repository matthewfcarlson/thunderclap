class Obj {
    char pad[0x2c];
    int value;

  public:
    bool Set(int v);
};
bool Obj::Set(int v) {
    value = v;
    return true;
}