class Obj_23df40 {
  public:
    char pad[0xc];
    int mVal;
    char Set(int v);
};

char Obj_23df40::Set(int v) {
    mVal = v;
    return 1;
}
