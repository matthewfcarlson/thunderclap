class Target_17f6f0 {
  public:
    char pad[0x14];
    bool Set(unsigned char value);
};

bool Target_17f6f0::Set(unsigned char value) {
    *((unsigned char*)pad + 0x14) = value;
    return true;
}
