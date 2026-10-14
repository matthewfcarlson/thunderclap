class Obj_1a29c0 {
  public:
    char pad[0x124];
    int mVal;
    char Set(int v);
};
char Obj_1a29c0::Set(int v) {
    mVal = v;
    return 1;
}
