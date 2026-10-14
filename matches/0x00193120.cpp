class Obj_193120 {
  public:
    char pad[0x64];
    int m64;
    char Set(int x);
};

char Obj_193120::Set(int x) {
    m64 = x;
    return 1;
}
