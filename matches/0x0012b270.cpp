class X {
  public:
    char pad[0x10];
    int mThing;
    bool SetThing(int value);
};

bool X::SetThing(int value) {
    mThing = value;
    return true;
}
