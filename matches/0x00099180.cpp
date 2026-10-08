struct C { char p0[4]; unsigned int flags; char p8[8]; int a; char p14[0xa8]; int b; };
int __fastcall FUN_00099180(C* p) {
    unsigned int v = p->flags >> 5;
    if ((unsigned char)v & 1) return p->b;
    return p->a;
}
