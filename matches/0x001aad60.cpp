class Obj_1aad60 {
  public:
    char mPad[0xc];
    int mField;
    char Set(int x);
};

char Obj_1aad60::Set(int x) {
    mField = x;
    return 1;
}
