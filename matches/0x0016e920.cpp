class Obj_16e920 {
  public:
    char Pad[0x54];
    int Value;
    char Set(int x);
};
char Obj_16e920::Set(int x) {
    Value = x;
    return 1;
}