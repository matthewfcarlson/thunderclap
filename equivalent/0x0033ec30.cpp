// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 3/4, incomplete)
// FUN_0033ec30 @ 0x0033ec30
typedef unsigned int uint;
extern uint *DAT_004d9858;
extern uint *DAT_004d985c;
extern uint DAT_004d9860;
extern uint DAT_00566200;
extern uint DAT_00566204;
extern void* __stdcall FUN_0033eb90(uint bytes);
extern void __stdcall FUN_0033ec00(void* p);
uint __stdcall FUN_0033ec30(uint value, uint size) {
    uint count = DAT_00566204;
    if (DAT_004d9860 == count) {
        uint* storage = (uint*)FUN_0033eb90(DAT_004d9860 * 16);
        uint capacity = DAT_004d9860;
        uint* source = DAT_004d9858;
        for (uint i=0;i<capacity;++i) storage[i]=source[i];
        uint* sizes = storage + capacity*2;
        source = DAT_004d985c;
        for (uint j=0;j<capacity;++j) sizes[j]=source[j];
        DAT_004d9860 = capacity*2;
        if (capacity*2 != 64) FUN_0033ec00(DAT_004d9858);
        count = DAT_00566204;
        DAT_004d985c = sizes;
        DAT_004d9858 = storage;
    }
    uint rounded = (size+31) & ~31u;
    uint total = DAT_00566200;
    uint adjustment = (((total >> 5) - (rounded >> 5) + 1) & 31) << 5;
    rounded += adjustment;
    DAT_00566200 = total + rounded;
    DAT_004d985c[count] = rounded;
    DAT_004d9858[count] = value;
    DAT_00566204 = count + 1;
    return value;
}