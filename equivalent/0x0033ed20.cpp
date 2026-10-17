// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 6/6)
// FUN_0033ed20 @ 0x0033ed20
typedef unsigned int uint;
extern uint DAT_00566200;
extern uint DAT_00566204;
extern uint *DAT_004d9858;
extern uint *DAT_004d985c;
extern uint __stdcall FUN_0033eb90(uint);
uint __stdcall FUN_0033ed20(uint size)
{
    uint aligned = (size + 31) & ~31u;
    uint base = FUN_0033eb90(DAT_00566200 + aligned);
    DAT_00566200 = 0;
    if (base != 0 && DAT_00566204 != 0) {
        uint offset = (uint)DAT_004d9858 - (uint)DAT_004d985c;
        uint *entry = DAT_004d985c;
        uint address = base + aligned;
        uint count = DAT_00566204;
        do {
            *(uint *)*(uint *)((char *)entry + offset) = address;
            address += *entry++;
        } while (--count != 0);
    }
    DAT_00566204 = 0;
    return base;
}