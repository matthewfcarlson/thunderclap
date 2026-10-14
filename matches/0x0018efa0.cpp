class Obj {
  public:
    char pad[0x44];
    int value;
    bool Set(int x);
};
bool Obj::Set(int x) {
    value = x;
    return true;
}
