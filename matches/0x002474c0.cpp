// The om allocator's allocate slot (0x004cc200 +4): an instance of the type's size and alignment from heap 0
// (the volatile read keeps MSVC's load order).
#include "decls/data/records.h"
extern "C" void FUN_00266eb0(int, int, int);
extern "C" void FUN_002474c0(int unused, OmType* type) {
    int size = *(volatile int*)&type->body.size;
    FUN_00266eb0(0, size, type->body.align);
}
