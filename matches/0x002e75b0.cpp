class Obj {
  public:
    char pad0[0x64];
    int flags;
    char pad68[0x108 - 0x68];
    int value;
    char pad10c[0x114 - 0x10c];
    unsigned char mode;
};
extern void __cdecl FUN_002dd690(Obj*, int*, int);
extern int __cdecl FUN_002e7500(int*);
int __cdecl target(Obj* p) {
    int q;
    int b = 1;
    if (p->mode & 0x20) {
        if ((p->flags & 0x300) == 0x300)
            b = 0;
    } else if (p->flags & 0x800)
        b = 0;
    FUN_002dd690(p, &q, 4);
    if (b) {
        return FUN_002e7500(&q) != p->value;
    }
    return 0;
}