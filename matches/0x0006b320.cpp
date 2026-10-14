class X_6b320 {
  public:
    char pad[0x38];
    int mThing;
    bool SetThing(int v);
};
bool X_6b320::SetThing(int v) {
    mThing = v;
    return true;
}
