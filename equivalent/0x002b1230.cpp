// STATUS: equivalent (tools/equiv.py level 3: 198 inputs, branch coverage 4/4)
// FUN_002b1230 @ 0x002b1230
struct Pair { int a; int b; };
struct Rec24 { char d[24]; };
struct PairRef { Rec24 *p; int v; };
struct OutVec {
    PairRef *data;
    void FUN_002b0fb0(int n, Pair *fill);
};
struct Table { char pad[0x10]; char *values; };
struct Target {
    char pad0[0x10];
    Table *table;
    char pad1[0x20 - 0x14];
    Rec24 *base;
    void FUN_002b1230(OutVec *out, int n, int *idxs, int off);
};
void Target::FUN_002b1230(OutVec *out, int n, int *idxs, int off)
{
    Pair zero;
    zero.a = 0;
    zero.b = 0;
    out->FUN_002b0fb0(n, &zero);
    for (int i = 0; i < n; i++) {
        out->data[i].p = base + idxs[i];
        out->data[i].v = *(int *)(table->values + (off << 2) + i * 4);
    }
}
