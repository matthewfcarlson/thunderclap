class Obj_193100 {
  public:
    char pad[0x60];
    int m60;
    unsigned char Flag(int v);
};

unsigned char Obj_193100::Flag(int v) {
    m60 = v;
    return 1;
}
