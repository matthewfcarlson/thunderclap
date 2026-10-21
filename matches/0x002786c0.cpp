// The original tail-jumps to the save interface's write 0x0027a460 (ret 0x24: 9 words) after moving its first two
// arguments up one slot and putting the drive in front: the call has 9 stack words and the third argument is
// dropped. Declared as such (native14 check 7; the 3-parameter spelling byte-matched but read 6 garbage words and
// left the stack 24 bytes off natively).
namespace core {
struct SignedWriter {
    int FUN_0027a460(void* drive, unsigned int handle, unsigned int mode, unsigned int offset, unsigned int destination,
                     unsigned int count, unsigned int* result, unsigned int flags, unsigned int context);
};
struct XboxSaveDrive {
    char padding[0xc0];
    SignedWriter writer;
    int vfunc_13(unsigned int handle, unsigned int mode, unsigned int unused, unsigned int offset,
                 unsigned int destination, unsigned int count, unsigned int* result, unsigned int flags,
                 unsigned int context);
};
int XboxSaveDrive::vfunc_13(unsigned int handle, unsigned int mode, unsigned int unused, unsigned int offset,
                            unsigned int destination, unsigned int count, unsigned int* result, unsigned int flags,
                            unsigned int context) {
    return writer.FUN_0027a460(this, handle, mode, offset, destination, count, result, flags, context);
}
} // namespace core
