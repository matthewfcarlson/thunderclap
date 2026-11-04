class A_237b80 {
  public:
    char pad[0x18];
    int mVal;
    bool SetPriority_00237b80(int x);
};
bool A_237b80::SetPriority_00237b80(int x) {
    mVal = x;
    return true;
}
