class Obj_5d530 {
  public:
    char SetState(char c);
    char mPad[0x38];
    char mState;
};

char Obj_5d530::SetState(char c) {
    mState = c;
    return 1;
}
