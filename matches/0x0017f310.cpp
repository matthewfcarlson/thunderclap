class Obj_17f310 {
  public:
    char Pad[0x10];
    int mVal;
    char Set(int v);
};
char Obj_17f310::Set(int v) {
    mVal = v;
    return 1;
}
