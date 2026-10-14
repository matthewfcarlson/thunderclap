class Obj {
  public:
    char pad[0x1ac];
    int m;
    int Set(int x);
};
int Obj::Set(int x) {
    m = x;
    return x;
}
