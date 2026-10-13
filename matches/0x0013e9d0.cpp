class Obj {
  public:
    char pad[0x50];
    int m50;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m50 = x;
    return true;
}