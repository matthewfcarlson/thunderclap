class Obj_685f0 {
  public:
    char pad[0xc];
    int mVal;
    char Set(int v);
};

char Obj_685f0::Set(int v) {
    mVal = v;
    return 1;
}
