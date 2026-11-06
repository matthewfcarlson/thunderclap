// (adr1) matches/0x00278060.cpp before the fix: XPP's gamepad type descriptor passed as an integer
typedef unsigned int uint;
typedef unsigned char byte_278060;
extern int __stdcall XGetDeviceChanges(int deviceType, uint* inserted, uint* removed);
void __fastcall FUN_00278060(byte_278060* state) {
    uint insertedMask;
    uint removedMask;
    int result = XGetDeviceChanges(0x3ea820, &insertedMask, &removedMask);
    if (result != 0) {
        byte_278060 insertedBits = (byte_278060)((((insertedMask >> 12) ^ insertedMask) & 0xf) ^ (insertedMask >> 12));
        byte_278060 removedBits = (byte_278060)((((removedMask >> 12) ^ removedMask) & 0xf) ^ (removedMask >> 12));
        state[0] = state[0] ^ removedBits ^ insertedBits;
        state[1] = state[1] | removedBits | insertedBits;
    }
}