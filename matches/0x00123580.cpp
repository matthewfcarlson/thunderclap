class Obj_123580 {
  public:
    char Set(char value);

  private:
    char mPad[0x14];
    char mValue;
};

char Obj_123580::Set(char value) {
    mValue = value;
    return 1;
}
