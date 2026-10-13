class Obj {
  public:
    char pad[0x10];
    int m10;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    m10 = x;
    return true;
}
