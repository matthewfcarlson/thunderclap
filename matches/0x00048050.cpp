class Obj_48050 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int x);
};

char Obj_48050::Set(int x) {
    mVal = x;
    return 1;
}
