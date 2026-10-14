class Obj_192a00 {
  public:
    char pad[0x64];
    int m64;
    bool Set(int x);
};
bool Obj_192a00::Set(int x) {
    m64 = x;
    return true;
}
