class Obj_16e9a0 {
  public:
    char SetX(int v);
    char pad[0x64];
    int m64;
};

char Obj_16e9a0::SetX(int v) {
    m64 = v;
    return 1;
}