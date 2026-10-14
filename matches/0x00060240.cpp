class Obj_60240 {
  public:
    char pad[0x18];
    int mVal;
    char Set(int v);
};

char Obj_60240::Set(int v) {
    mVal = v;
    return 1;
}
