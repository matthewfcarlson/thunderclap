// (adr1) matches/0x00278060.cpp with the descriptor as a symbol
typedef unsigned int uint;
typedef unsigned char byte_278060;
extern int __stdcall XGetDeviceChanges(void* deviceType, uint* inserted, uint* removed);
extern "C" char DAT_003ea820;
void __fastcall FUN_00278060(byte_278060* state) {
    uint insertedMask;
    uint removedMask;
    int result = XGetDeviceChanges(&DAT_003ea820, &insertedMask, &removedMask);
    if (result != 0) {
        byte_278060 insertedBits = (byte_278060)((((insertedMask >> 12) ^ insertedMask) & 0xf) ^ (insertedMask >> 12));
        byte_278060 removedBits = (byte_278060)((((removedMask >> 12) ^ removedMask) & 0xf) ^ (removedMask >> 12));
        state[0] = state[0] ^ removedBits ^ insertedBits;
        state[1] = state[1] | removedBits | insertedBits;
    }
}