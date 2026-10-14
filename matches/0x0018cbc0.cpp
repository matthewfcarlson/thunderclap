class Obj_18cbc0 {
  public:
    char pad[0x14];
    int mVal;
    char Set(int v);
};
char Obj_18cbc0::Set(int v) {
    mVal = v;
    return 1;
}
