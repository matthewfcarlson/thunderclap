class Obj_17f6d0 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int v);
};

char Obj_17f6d0::Set(int v) {
    mVal = v;
    return 1;
}
