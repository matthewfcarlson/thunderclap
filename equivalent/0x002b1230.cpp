// STATUS: equivalent (tools/equiv.py level 3: 198 inputs, branch coverage 4/4)
// FUN_002b1230 @ 0x002b1230
struct Pair_2b1230 { int a; int b; };
struct Rec24_2b1230 { char d[24]; };
struct PairRef { Rec24_2b1230 *p; int v; };
struct OutVec {
    PairRef *data;
    void FUN_002b0fb0(int n, Pair_2b1230 *fill);
};
struct Table_2b1230 { char pad[0x10]; char *values; };
struct Target_2b1230 {
    char pad0[0x10];
    Table_2b1230 *table;
    char pad1[0x20 - 0x14];
    Rec24_2b1230 *base;
    void FUN_002b1230(OutVec *out, int n, int *idxs, int off);
};
void Target_2b1230::FUN_002b1230(OutVec *out, int n, int *idxs, int off)
{
    Pair_2b1230 zero;
    zero.a = 0;
    zero.b = 0;
    out->FUN_002b0fb0(n, &zero);
    for (int i = 0; i < n; i++) {
        out->data[i].p = base + idxs[i];
        out->data[i].v = *(int *)(table->values + (off << 2) + i * 4);
    }
}
