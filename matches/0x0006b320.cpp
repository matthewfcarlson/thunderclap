class X {
  public:
    char pad[0x38];
    int mThing;
    bool SetThing(int v);
};
bool X::SetThing(int v) {
    mThing = v;
    return true;
}
