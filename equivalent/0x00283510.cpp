// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00283510 @ 0x00283510
struct RefObj { virtual void AddRef(); virtual void Release(); };
// 0x60-byte records; record i holds the id/flag of slot i and the object of slot i-1 (same array, offset by one)
struct Rec {
    RefObj* obj;
    int f4, f8, fc, f10;
    int f14;
    int id;
    char flag;
    char pad[0x60 - 0x1d];
};
class Table {
public:
    Rec rec[102];
    int FUN_002804f0(int id, int a, int b, int c);
    int Add(RefObj* o, int a, int b, int c);
};
int Table::Add(RefObj* o, int a, int b, int c) {
    int i = 0;
    while (i < 100) {
        if (!rec[i + 1].obj) break;
        i++;
    }
    if (i >= 100) return 0;
    int id = rec[0].f10;
    rec[i].id = id;
    rec[i].flag = 0;
    if (o) o->AddRef();
    RefObj* old = rec[i + 1].obj;
    if (old) old->Release();
    rec[i + 1].obj = o;
    rec[i + 1].f4 = 0; rec[i + 1].f8 = 0; rec[i + 1].fc = 0;
    rec[i + 1].f10 = 0xffff;
    FUN_002804f0(id, a, b, c);
    rec[0].f10++;
    return id;
}
