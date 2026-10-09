typedef unsigned int uint;
struct Item { int type; int value; };
Item* __fastcall GetItem(int, int);
int __cdecl Check(int, Item*);
void __cdecl Update(int);
int __cdecl FUN_00213190(int a, int b) {
    Item* p = GetItem(b, a);
    if (p->type == 4) return p->value + 0x10;
    int result = Check(a, p) ? p->value + 0x10 : 0;
    volatile uint* q = (volatile uint*)(*(uint*)(a + 0x10));
    uint high = q[19];
    if (high >= q[18]) Update(a);
    return result;
}