class C_16eed0 {
  public:
    char pad[0x10];
    int mValue;
    bool Init(int value);
};

bool C_16eed0::Init(int value) {
    mValue = value;
    return true;
}
