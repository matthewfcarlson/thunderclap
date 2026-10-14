// STATUS: equivalent (tools/equiv.py level 3: 16452 inputs, branch coverage 4/4)
// FUN_0033ec30 @ 0x0033ec30
// FUN_0033ec30 @ 0x0033ec30
typedef unsigned int uint_33ec30;
extern uint_33ec30 *DAT_004d9858;
extern uint_33ec30 *DAT_004d985c;
extern uint_33ec30 DAT_004d9860;
extern uint_33ec30 DAT_00566200;
extern uint_33ec30 DAT_00566204;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern void* __stdcall FUN_0033eb90(uint_33ec30 bytes);
extern void __stdcall FUN_0033ec00(void* p);
uint_33ec30 __stdcall FUN_0033ec30(uint_33ec30 value, uint_33ec30 size) {
    uint_33ec30 count = DAT_00566204;
    if (DAT_004d9860 == count) {
        uint_33ec30* storage = (uint_33ec30*)FUN_0033eb90(DAT_004d9860 * 16);
        uint_33ec30 capacity = DAT_004d9860;
        uint_33ec30* source = DAT_004d9858;
        memcpy(storage, source, capacity * 4);
        uint_33ec30* sizes = storage + capacity*2;
        source = DAT_004d985c;
        memcpy(sizes, source, capacity * 4);
        DAT_004d9860 = capacity*2;
        if (capacity*2 != 64) FUN_0033ec00(DAT_004d9858);
        count = DAT_00566204;
        DAT_004d985c = sizes;
        DAT_004d9858 = storage;
    }
    uint_33ec30 rounded = (size+31) & ~31u;
    uint_33ec30 total = DAT_00566200;
    uint_33ec30 adjustment = (((total >> 5) - (rounded >> 5) + 1) & 31) << 5;
    rounded += adjustment;
    DAT_00566200 = total + rounded;
    DAT_004d985c[count] = rounded;
    DAT_004d9858[count] = value;
    DAT_00566204 = count + 1;
    return value;
}