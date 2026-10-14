class O {
  public:
    char pad[0x84];
    char mFlag;
    bool SetFlag(char value);
};

bool O::SetFlag(char value) {
    mFlag = value;
    return true;
}
