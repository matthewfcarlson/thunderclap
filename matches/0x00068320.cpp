class Obj {
    char pad[16];
    int value;

  public:
    bool Set(int v);
};
bool Obj::Set(int v) {
    value = v;
    return true;
}