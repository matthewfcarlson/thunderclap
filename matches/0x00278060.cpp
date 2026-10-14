typedef unsigned int uint;
typedef unsigned char byte_278060;
extern int __stdcall XGetDeviceChanges(int deviceType, uint* inserted, uint* removed);
void __fastcall FUN_00278060(byte_278060* param_1) {
    uint local_8;
    uint local_4;
    int result = XGetDeviceChanges(0x3ea820, &local_8, &local_4);
    if (result != 0) {
        byte_278060 bVar3 = (byte_278060)((((local_8 >> 12) ^ local_8) & 0xf) ^ (local_8 >> 12));
        byte_278060 bVar1 = (byte_278060)((((local_4 >> 12) ^ local_4) & 0xf) ^ (local_4 >> 12));
        param_1[0] = param_1[0] ^ bVar1 ^ bVar3;
        param_1[1] = param_1[1] | bVar1 | bVar3;
    }
}