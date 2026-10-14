// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0fc0 @ 0x001e0fc0
// 0x001e0fc0: swap two 20-byte records
struct Record {
    int a, b, c, d;
    short e;
    short f;
};

void FUN_001e0fc0(Record* x, Record* y)
{
    Record t = *x;
    *x = *y;
    *y = t;
}
