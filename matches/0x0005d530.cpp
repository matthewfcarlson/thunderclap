class Obj {
  public:
    char SetState(char c);
    char mPad[0x38];
    char mState;
};

char Obj::SetState(char c) {
    mState = c;
    return 1;
}
