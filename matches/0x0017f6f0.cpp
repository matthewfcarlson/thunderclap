class Target {
  public:
    char pad[0x14];
    bool Set(unsigned char value);
};

bool Target::Set(unsigned char value) {
    *((unsigned char*)pad + 0x14) = value;
    return true;
}
