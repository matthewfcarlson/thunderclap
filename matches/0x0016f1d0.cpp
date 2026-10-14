class Obj_16f1d0 {
  public:
    char Pad[0x10];
    int m10;
    char Set(int x);
};
char Obj_16f1d0::Set(int x) {
    m10 = x;
    return 1;
}
