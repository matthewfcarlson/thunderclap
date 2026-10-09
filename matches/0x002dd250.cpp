struct Obj {
    char pad0[0x64];
    unsigned int flags64;
    char pad68[0x11e - 0x68];
    unsigned char state;
    unsigned char level;
    char pad120[3];
    unsigned char result;
    char pad124[2];
    unsigned short value;
};
void FUN_002dd250(Obj* p, unsigned char b, int mode) {
    unsigned int* q = (unsigned int*)((char*)p + 0x68);
    *q |= 0x8000;
    p->value = b;
    if (mode == 1)
        p->flags64 |= 0x80;
    else
        p->flags64 &= 0xffffff7f;
    if (p->state == 2)
        p->result = 4;
    if (p->state == 0 && p->level >= 8)
        p->result = 2;
}
