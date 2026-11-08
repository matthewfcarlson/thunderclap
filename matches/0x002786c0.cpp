// The original tail-jumps to the save interface's write 0x0027a460 (ret 0x24: 9 words) after moving its first two
// arguments up one slot and putting the drive in front: the call has 9 stack words and the third argument is
// dropped. Declared as such (native14 check 7; the 3-parameter spelling byte-matched but read 6 garbage words and
// left the stack 24 bytes off natively).
#include "decls/data/records.h"
namespace core {
struct SignedWriter {
    int FUN_0027a460(void* drive, unsigned int handle, unsigned int mode, unsigned int offset, unsigned int destination,
                     unsigned int count, unsigned int* result, unsigned int flags, unsigned int context);
};
// records.h CoreXboxSaveDrive: the core::SignedWriter base at +0xc0
struct XboxSaveDrive_2786c0 : CoreXboxSaveDrive {
    int vfunc_13(unsigned int handle, unsigned int mode, unsigned int unused, unsigned int offset,
                 unsigned int destination, unsigned int count, unsigned int* result, unsigned int flags,
                 unsigned int context);
};
int XboxSaveDrive_2786c0::vfunc_13(unsigned int handle, unsigned int mode, unsigned int unused, unsigned int offset,
                            unsigned int destination, unsigned int count, unsigned int* result, unsigned int flags,
                            unsigned int context) {
    return ((SignedWriter*)&vftableWriter)->FUN_0027a460(this, handle, mode, offset, destination, count, result, flags, context);
}
} // namespace core
