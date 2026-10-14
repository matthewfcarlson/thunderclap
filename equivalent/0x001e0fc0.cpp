// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0fc0 @ 0x001e0fc0
// 0x001e0fc0: swap two 20-byte records
struct Record_1e0fc0 {
    int a, b, c, d;
    short e;
    short f;
};

void FUN_001e0fc0(Record_1e0fc0* x, Record_1e0fc0* y)
{
    Record_1e0fc0 t = *x;
    *x = *y;
    *y = t;
}
