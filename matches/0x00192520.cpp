class Obj_192520 {
  public:
    char pad[0xb4];
    int mVal;
    char Set(int val);
};

char Obj_192520::Set(int val) {
    mVal = val;
    return 1;
}
