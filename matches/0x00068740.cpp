class Obj {
  public:
    char pad[0x94];
    int m;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    m = x;
    return true;
}
