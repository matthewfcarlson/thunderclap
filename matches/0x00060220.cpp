class Obj_60220 {
  public:
    char Set(int x);
    char mPad[0x10];
    int m10;
};

char Obj_60220::Set(int x) {
    m10 = x;
    return 1;
}
