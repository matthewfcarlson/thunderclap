class X {
  public:
    char pad[0xcf];
    char mFlag;
    void SetFlag(char c);
};

void X::SetFlag(char c) {
    mFlag = c;
}
