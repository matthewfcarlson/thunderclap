class Obj_12e190 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int v);
};
char Obj_12e190::Set(int v) {
    mVal = v;
    return 1;
}