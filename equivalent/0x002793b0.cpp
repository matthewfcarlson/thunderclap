// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 14/14)
// core::XboxSaveDrive::vfunc_19 @ 0x002793b0
namespace XAPILIB { unsigned long __stdcall GetLastError(); }
extern "C" int __stdcall FUN_003565ca(int handle, void* data);
namespace core {
struct SaveSlot { char name[0x204]; int handle; };
struct XboxSaveDrive {
    char unused[0xb4];
    int state;
    char reserved[0x38];
    SaveSlot slots[1];
    bool FUN_002788c0();
    int FUN_00278d30(void* result, void* data, int handle, void* name);
    int FUN_002787c0(unsigned long error);
    int vfunc_19(int* index, void* result);
};
int XboxSaveDrive::vfunc_19(int* index, void* result) {
    SaveSlot& slot = slots[*index];
    if (slot.handle == -1) {
        state = 1;
        return 0;
    }
    if (!FUN_002788c0()) return 0;
    char data[0x344];
    for (;;) {
        if (FUN_003565ca(slot.handle, data)) {
            int answer = FUN_00278d30(result, data, slot.handle, slot.name);
            if (answer == 2) continue;
            if (answer == 1) return 0;
            if (answer != 0) state = 0;
            return 1;
        }
        unsigned long error = XAPILIB::GetLastError();
        if (error == 0x12) {
            *(unsigned char*)((char*)result + 4) = 0;
            *(int*)result = 2;
            state = 0;
            return 1;
        }
        state = FUN_002787c0(error);
        return 0;
    }
}
}