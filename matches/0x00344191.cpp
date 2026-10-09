typedef void (*Fn)();
extern void __cfltcvt();
extern void __fassign();
extern void FUN_003483b0();
extern void LAB_00348408();
extern void LAB_00348453();
Fn table[6];
void FUN_00344191() {
    table[0] = __cfltcvt;
    table[1] = LAB_00348408;
    table[2] = __fassign;
    table[3] = FUN_003483b0;
    table[4] = LAB_00348453;
    table[5] = __cfltcvt;
}