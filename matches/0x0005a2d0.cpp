class O {
  public:
    char pad[0x0c];
    int mVal;
    bool Set(int x);
};

bool O::Set(int x) {
    mVal = x;
    return true;
}
