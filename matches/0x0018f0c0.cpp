class Obj_18f0c0 {
  public:
    char pad[0x64];
    int m64;
    char Set(int v);
};

char Obj_18f0c0::Set(int v) {
    m64 = v;
    return 1;
}
