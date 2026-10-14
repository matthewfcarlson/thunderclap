class Obj_15b340 {
  public:
    char pad[0xc];
    int mVal;
    char Set(int v);
};

char Obj_15b340::Set(int v) {
    mVal = v;
    return 1;
}
