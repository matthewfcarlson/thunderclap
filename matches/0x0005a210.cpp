class Obj {
  public:
    char pad[0x64];
    int m64;
    char Set(int v);
};
char Obj::Set(int v) {
    m64 = v;
    return 1;
}
