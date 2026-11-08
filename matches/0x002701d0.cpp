#include "decls/data/engine/core.h"
#include "decls/data/records.h"

#include "compat/ptr.h"
#include "gen/core.h"
#include "gen/owners.h"

extern "C" int sprintf(char*, const char*, ...);
extern "C" void* FUN_00266e00(int a, int b);
// the child pool: core::MemoryPool (0x00270170 constructs it), named by its constructor's address with its layout
// (records.h CoreMemoryPool), set up by 0x00270020
inline void* operator new(unsigned int, void* p) { return p; }
class FUN_00270170 : public CoreMemoryPool {
  public:
    FUN_00270170();
};
void* core::MemoryPool::vfunc_13() {
    char buf[0x80];
    if (!(*(unsigned int * *)&this->f_10)) {
        if (!(*(core::MemoryPool * *)&this->f_30) && this->f_24 > 0) {
            int a = this->f_14;
            DAT_004cdbb0 = a;
            HULK_SIZE32(FUN_00270170, 0x34);
            void* p = FUN_00266e00(a, (int)sizeof(FUN_00270170));
            (*(core::MemoryPool * *)&this->f_30) = p ? (core::MemoryPool*)new (p) FUN_00270170 : 0;
            if ((*(core::MemoryPool * *)&this->f_30)) {
                sprintf(buf, "child of %8.8X[MemoryPool]", this);
                (*(owners::Pool_270020 * *)&this->f_30)->FUN_00270020(0, (*(unsigned int *)&this->f_1c), this->f_24, this->f_24, (void*)(hulk_uintptr)this->f_14, (hulk_uintptr)buf, 1);
                (*(core::MemoryPool * *)&this->f_30)->vfunc_0();
            }
        }
        if ((*(core::MemoryPool * *)&this->f_30))
            return (void*)((*(core::MemoryPool * *)&this->f_30)->vfunc_13());
        return (void*)(0);
    }
    unsigned* p = (*(unsigned int * *)&this->f_10);
    (*(unsigned int * *)&this->f_10) = (unsigned*)*(hulk_uintptr*)p;
    (*(unsigned int *)&this->f_28)++;
    (*(unsigned int *)&this->f_2c) = (*(unsigned int *)&this->f_28) > (*(unsigned int *)&this->f_2c) ? (*(unsigned int *)&this->f_28) : (*(unsigned int *)&this->f_2c);
    return (void*)(p);
}
