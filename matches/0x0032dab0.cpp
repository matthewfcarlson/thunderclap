class X_32dab0 {
  public:
    char pad[0x90];
    char mFlag;
    void SetFlag(int* p);
};

void X_32dab0::SetFlag(int* p) {
    mFlag = (char)(p != 0);
}
