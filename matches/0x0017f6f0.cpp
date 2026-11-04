class Target_17f6f0 {
  public:
    char pad[0x14];
    bool SetSimulate_0017f6f0(unsigned char value);
};

bool Target_17f6f0::SetSimulate_0017f6f0(unsigned char value) {
    *((unsigned char*)pad + 0x14) = value;
    return true;
}
