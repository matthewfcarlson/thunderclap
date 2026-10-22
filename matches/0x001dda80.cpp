struct Bits {
    unsigned short a : 12;
    unsigned short b : 1;
    unsigned short c : 3;
};
class CSPManager_1dda80 {
  public:
    unsigned char check(int index);
    char pad[0x62a];
};
unsigned char CSPManager_1dda80::check(int index) {
    if (index < 0 || index >= 0x800)
        return 0;
    short n = *(short*)((char*)this + 0x62a + index * 40);
    return ((Bits*)((char*)this + (n + 0x104e) * 20))->b;
}