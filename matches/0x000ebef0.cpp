class MenuSelector { public: void *vptr; char pad[0x1da4]; unsigned char flag; unsigned char data[0x80*0x40]; void Init(unsigned int, unsigned int); MenuSelector *Target(unsigned int, unsigned int); };
MenuSelector *MenuSelector::Target(unsigned int a, unsigned int b) {
    Init(a, b);
    vptr = (void *)0x40c554;
    flag = 1;
    for (int i = 0; i < 0x80; ++i) data[i * 0x40] = 0;
    return this;
}