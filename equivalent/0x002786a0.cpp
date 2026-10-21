// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// core::XboxSaveDrive::vfunc_12 @ 0x002786a0
// The original tail-jumps to the save interface's read 0x0027a370 (ret 0x20: 8 words) after moving its first two
// arguments up one slot and putting the drive in front: the call has 8 stack words and the third argument is
// dropped. Declared as such (native14 check 7: with 3 parameters the callee read 5 garbage words and popped 32 bytes).
namespace core {
struct SaveInterface {
    int FUN_0027a370(void* drive, unsigned int key, unsigned int mode, unsigned int start, unsigned int destination,
                     unsigned int count, unsigned int* completed, unsigned int flags);
};
struct XboxSaveDrive {
    char reserved[0xbc];
    SaveInterface saveInterface;
    int vfunc_12(unsigned int key, unsigned int mode, unsigned int unused, unsigned int start, unsigned int destination,
                 unsigned int count, unsigned int* completed, unsigned int flags);
};
int XboxSaveDrive::vfunc_12(unsigned int key, unsigned int mode, unsigned int unused, unsigned int start,
                            unsigned int destination, unsigned int count, unsigned int* completed, unsigned int flags) {
    return saveInterface.FUN_0027a370(this, key, mode, start, destination, count, completed, flags);
}
}
