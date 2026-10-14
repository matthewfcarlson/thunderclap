class Obj_16f8a0 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int x);
};
bool Obj_16f8a0::Set(int x) {
    m10 = x;
    return true;
}
