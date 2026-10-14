class Obj_683d0 {
  public:
    char Set(int value);
    char mPad[0x1c];
    int mValue;
};

char Obj_683d0::Set(int value) {
    mValue = value;
    return 1;
}
