class Obj {
    char pad[12];
    int value;

  public:
    bool Set(int x);
};
bool Obj::Set(int x) {
    value = x;
    return true;
}