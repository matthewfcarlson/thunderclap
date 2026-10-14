class Obj_16fa00 {
  public:
    char pad[0xc];
    int m;
    bool Set(int x);
};
bool Obj_16fa00::Set(int x) {
    m = x;
    return true;
}