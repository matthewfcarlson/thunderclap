class Obj_5a210 {
  public:
    char pad[0x64];
    int m64;
    char Set(int v);
};
char Obj_5a210::Set(int v) {
    m64 = v;
    return 1;
}
