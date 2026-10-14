class Obj_1332d0 {
  public:
    char pad[0x28];
    int mVal;
    char Set(int v);
};
char Obj_1332d0::Set(int v) {
    mVal = v;
    return 1;
}
