class Obj_17f8f0 {
  public:
    char pad[0x18];
    int mVal;
    char Set(int v);
};
char Obj_17f8f0::Set(int v) {
    mVal = v;
    return 1;
}
