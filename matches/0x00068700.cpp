class O_68700 {
  public:
    char pad[0x84];
    char mFlag;
    bool SetFlag(char value);
};

bool O_68700::SetFlag(char value) {
    mFlag = value;
    return true;
}
