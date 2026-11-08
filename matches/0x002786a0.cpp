// The original tail-jumps to the save interface's read 0x0027a370 (ret 0x20: 8 words) after moving its first two
// arguments up one slot and putting the drive in front: the call has 8 stack words and the third argument is
// dropped. Declared as such (native14 check 7: with 3 parameters the callee read 5 garbage words and popped 32 bytes).
#include "decls/data/records.h"
namespace core {
struct SaveInterface {
    int FUN_0027a370(void* drive, unsigned int key, unsigned int mode, unsigned int start, unsigned int destination,
                     unsigned int count, unsigned int* completed, unsigned int flags);
};
// records.h CoreXboxSaveDrive: the core::SignedReader base at +0xbc
struct XboxSaveDrive_2786a0 : CoreXboxSaveDrive {
    int vfunc_12(unsigned int key, unsigned int mode, unsigned int unused, unsigned int start, unsigned int destination,
                 unsigned int count, unsigned int* completed, unsigned int flags);
};
int XboxSaveDrive_2786a0::vfunc_12(unsigned int key, unsigned int mode, unsigned int unused, unsigned int start,
                            unsigned int destination, unsigned int count, unsigned int* completed, unsigned int flags) {
    return ((SaveInterface*)&vftableReader)->FUN_0027a370(this, key, mode, start, destination, count, completed, flags);
}
}
