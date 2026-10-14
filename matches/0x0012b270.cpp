class X_12b270 {
  public:
    char pad[0x10];
    int mThing;
    bool SetThing(int value);
};

bool X_12b270::SetThing(int value) {
    mThing = value;
    return true;
}
