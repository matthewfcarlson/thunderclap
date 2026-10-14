class Obj_11b830 {
  public:
    char pad[0x14];
    int mVal;
    char Set(int v);
};

char Obj_11b830::Set(int v) {
    mVal = v;
    return 1;
}
