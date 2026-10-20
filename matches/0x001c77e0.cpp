extern "C" char DAT_00421a3c[];
class StoreBase_1c77e0 {
  public:
    StoreBase_1c77e0(unsigned int, unsigned char);
    void init(unsigned int);
};
StoreBase_1c77e0::StoreBase_1c77e0(unsigned int arg, unsigned char flag) {
    unsigned char* p = (unsigned char*)this;
    *(unsigned int*)p = ((int)DAT_00421a3c);
    *(unsigned int*)(p + 8) = 0;
    *(unsigned int*)(p + 12) = 0;
    *(unsigned int*)(p + 16) = 0xffffffff;
    *(unsigned int*)(p + 20) = 0;
    unsigned int* q = (unsigned int*)(p + 24);
    int i;
    for (i = 0; i < 16; i++) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    *(unsigned int*)(p + 0x118) = 0;
    *(unsigned char*)(p + 0x11c) = flag;
    init(arg);
}