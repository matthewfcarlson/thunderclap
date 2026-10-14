class Obj_1150d0 {
  public:
    char pad[0xc];
    int mVal;
    char Set(int v);
};

char Obj_1150d0::Set(int v) {
    mVal = v;
    return 1;
}
