class X {
  public:
    char pad[0x90];
    char mFlag;
    void SetFlag(int* p);
};

void X::SetFlag(int* p) {
    mFlag = (char)(p != 0);
}
