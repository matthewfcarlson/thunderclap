class Obj_5d7d0 {
  public:
    char Set(int v);
    char pad[0x18];
    int mVal;
};
char Obj_5d7d0::Set(int v) {
    mVal = v;
    return 1;
}