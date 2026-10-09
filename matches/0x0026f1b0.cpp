class XboxDrive {
    char pad[0xbc];
    unsigned int value;

  public:
    unsigned int vfunc_6();
};
unsigned int XboxDrive::vfunc_6() {
    return value;
}