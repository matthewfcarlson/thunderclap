class O_5a2d0 {
  public:
    char pad[0x0c];
    int mVal;
    bool Set(int x);
};

bool O_5a2d0::Set(int x) {
    mVal = x;
    return true;
}
