class Obj {
  public:
    char pad[0x20];
    int m20;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    m20 = x;
    return true;
}
