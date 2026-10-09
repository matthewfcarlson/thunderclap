class FETextInput {
  public:
    char pad[0x74];
    unsigned char flag;
    char pad2[0x178 - 0x75];
    int value;
    void vfunc_14(int);
};
void FETextInput::vfunc_14(int) {
    if (flag)
        value = 0;
}