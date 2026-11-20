// FUN_0008c470 @ 0x0008c470
// (integ3, allocty, must fail) the memory-card manager's U: slot (src/game/global/CGameFlowManager.cpp, D142): the slot comes from
// the allocator declared to return State*, a stubbed initializer sets it up, and the code reads slot->drive before it
// writes it. The allocation's untouched bytes are State's leaves: a null drive is null on both targets (raw bytes the
// same byte for byte read as an 8-byte pointer were a crash64 the 32-bit run never saw)
struct Owner;
struct Pair { unsigned a, b; };
struct Iface {
    virtual void attach(Owner*, unsigned);
    virtual unsigned open(Pair*, unsigned);
};
struct Media { int words[5]; char label[0x40]; };
struct State { Iface* drive; void* file; Media pending; Media media; unsigned result; int status[5]; };
extern "C" State* __cdecl FUN_0008d6d0(unsigned);
extern "C" Pair* __cdecl FUN_0008d690(unsigned);
extern void __cdecl InitSlot(State*, const char*, unsigned, unsigned);
extern void __cdecl FUN_0008d330(Pair*);
struct Owner { const void* vftable; unsigned parameter; State* slots; void FUN_0008c470(unsigned); };
void Owner::FUN_0008c470(unsigned value) {
    parameter = value;
    slots = FUN_0008d6d0((unsigned)sizeof(State));
    Pair* pair = FUN_0008d690((unsigned)sizeof(Pair));
    pair->a = 0; pair->b = 0;
    *(void**)((char*)slots + 4) = 0;   // (must fail: file at its 32-bit offset, over the drive pointer's upper half)
    InitSlot(slots, "U:", 1, 0);
    if (slots->drive) {
        slots->drive->attach(this, 0);
        slots->result = slots->drive->open(pair, parameter);
        slots->media.label[0] = 0; slots->file = 0;
        slots->status[0] = 1; slots->status[4] = 1;
    } else {
        slots->drive = 0;
    }
    FUN_0008d330(pair);
}
