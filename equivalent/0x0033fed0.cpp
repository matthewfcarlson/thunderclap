// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033fed0 @ 0x0033fed0
// Permutes the 8-byte slots of a 0x78-byte block (register argument: eax = block).
struct Slot { int a; int b; };
struct FSlot { float a; float b; };

struct Block {
    char pad0[8];
    Slot s08;      // 0x08
    Slot s10;      // 0x10
    Slot s18;      // 0x18
    Slot s20;      // 0x20
    Slot s28;      // 0x28
    Slot s30;      // 0x30
    Slot s38;      // 0x38
    Slot s40;      // 0x40
    Slot s48;      // 0x48
    Slot s50;      // 0x50
    Slot s58;      // 0x58
    Slot s60;      // 0x60
    Slot s68;      // 0x68
    Slot s70;      // 0x70
};

// equiv-conv: FUN_0033fed0 eax
void __cdecl FUN_0033fed0(Block* m)
{
    Slot c = m->s18;
    Slot e = m->s28;
    Slot f = m->s38;
    Slot i = m->s58;
    FSlot x = *(FSlot*)&m->s08;
    FSlot y = *(FSlot*)&m->s10;

    m->s08 = m->s40;
    FSlot* d = (FSlot*)&m->s20;
    Slot old20 = m->s20;
    *d = y;
    m->s10 = old20;
    *(FSlot*)&m->s40 = x;
    m->s18 = m->s60;
    m->s28 = m->s50;
    m->s38 = m->s70;
    m->s50 = e;
    m->s58 = m->s68;
    m->s60 = c;
    m->s68 = i;
    m->s70 = f;
}
