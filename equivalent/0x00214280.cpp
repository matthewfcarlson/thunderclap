// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 16/16)
// FUN_00214280 @ 0x00214280
// FUN_00214280 @ 0x00214280
struct Data { char pad0[0x28]; int length; char pad1[0x47-0x2c]; unsigned char minimum; };
// equiv-conv: FUN_00214280 ecx edx eax
int FUN_00214280(int value, Data *data, int mode) {
    if (mode == 0) return value == 0 ? 1 : 0;
    if (mode == 2) return value < data->minimum ? 1 : 0;
    if (mode == 3 && value >= data->minimum) {
        if (value < 250 || value - 250 >= data->length) return 0;
    }
    return 1;
}
