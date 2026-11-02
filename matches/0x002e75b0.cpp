class Obj_2e75b0 {
  public:
    char pad0[0x64];
    int flags;
    char pad68[0x108 - 0x68];
    int value;
    char pad10c[0x114 - 0x10c];
    unsigned char mode;
};
extern void __cdecl FUN_002dd690(Obj_2e75b0*, int*, int);
extern int __cdecl FUN_002e7500(int*);
extern "C" int __cdecl FUN_002e75b0(void * p) {
    int q;
    int b = 1;
    if (((Obj_2e75b0 *)p)->mode & 0x20) {
        if ((((Obj_2e75b0 *)p)->flags & 0x300) == 0x300)
            b = 0;
    } else if (((Obj_2e75b0 *)p)->flags & 0x800)
        b = 0;
    FUN_002dd690(((Obj_2e75b0 *)p), &q, 4);
    if (b) {
        return FUN_002e7500(&q) != ((Obj_2e75b0 *)p)->value;
    }
    return 0;
}