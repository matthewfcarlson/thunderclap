#include "compat/ptr.h"
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct Allocator {
    void* FUN_002888c0(unsigned int, int);
};
namespace pure3d {
struct FUN_0028b420 {
    virtual void unusedVirtual();
    int unused4;
    int unused8;
    Allocator* allocator;
    int count;
    int unused14;
    void* values;
    FUN_0028b420(int first, int second);
};
struct IntChannel : public FUN_0028b420 {
    virtual void unusedVirtual();
    IntChannel(int first, int second);
};
IntChannel::IntChannel(int first, int second) : FUN_0028b420(first, second) {
    values = 0;
    if (allocator == 0)
        values = FUN_0008d6d0(count * 4);
    else
        values = allocator->FUN_002888c0(count * 4, 3);
}
} // namespace pure3d
