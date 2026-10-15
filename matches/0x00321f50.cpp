namespace pure3d {
class pddiBaseContext {
  public:
    unsigned char vfunc_90(unsigned int);
};
class d3dContext : public pddiBaseContext {
  public:
    unsigned char vfunc_90(unsigned int);
};
unsigned char d3dContext::vfunc_90(unsigned int x) {
    switch (x) {
    case 0x101:
    case 0x102:
    case 0x103:
    case 0x106:
    case 0x500001:
    case 0x500002:
    case 0x500004:
        return 1;
    default:
        return pddiBaseContext::vfunc_90(x);
    }
}
} // namespace pure3d