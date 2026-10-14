class Obj_1330c0 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int v);
};

char Obj_1330c0::Set(int v) {
    mVal = v;
    return 1;
}
