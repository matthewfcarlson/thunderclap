class Obj {
  public:
    char Set(char value);

  private:
    char mPad[0x14];
    char mValue;
};

char Obj::Set(char value) {
    mValue = value;
    return 1;
}
