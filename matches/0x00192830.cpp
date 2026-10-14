class Obj {
  public:
    char pad[12];
    int m10;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m10 = x;
    return true;
}
