class C_123670 {
  public:
    char pad[0x15];
    char field;
    unsigned char SetUseGroundPoint_00123670(unsigned char x);
};

unsigned char C_123670::SetUseGroundPoint_00123670(unsigned char x) {
    field = x;
    return 1;
}
