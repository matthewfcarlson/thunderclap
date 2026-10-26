#include "compat/ptr.h"
#include "gen/core.h"

extern "C" int sprintf(char*, const char*, ...);
extern unsigned gTag;
void* Alloc(unsigned, unsigned);
namespace core {
struct Child_2701d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void* v13();
    Child_2701d0* Init();
    void Setup(int, unsigned, unsigned, unsigned, unsigned, char*, int);
};
} // namespace core
void* core::MemoryPool::vfunc_13() {
    char buf[0x80];
    if (!(*(unsigned int * *)&this->f_10)) {
        if (!(*(Child_2701d0 * *)&this->f_30) && this->f_24 > 0) {
            unsigned a = this->f_14;
            gTag = a;
            void* p = Alloc(a, 0x34);
            (*(Child_2701d0 * *)&this->f_30) = p ? ((Child_2701d0*)p)->Init() : 0;
            if ((*(Child_2701d0 * *)&this->f_30)) {
                sprintf(buf, "child of %8.8X[MemoryPool]", this);
                (*(Child_2701d0 * *)&this->f_30)->Setup(0, (*(unsigned int *)&this->f_1c), this->f_24, this->f_24, this->f_14, buf, 1);
                (*(Child_2701d0 * *)&this->f_30)->v0();
            }
        }
        if ((*(Child_2701d0 * *)&this->f_30))
            return (void*)((*(Child_2701d0 * *)&this->f_30)->v13());
        return (void*)(0);
    }
    unsigned* p = (*(unsigned int * *)&this->f_10);
    (*(unsigned int * *)&this->f_10) = (unsigned*)*(hulk_uintptr*)p;
    (*(unsigned int *)&this->f_28)++;
    (*(unsigned int *)&this->f_2c) = (*(unsigned int *)&this->f_28) > (*(unsigned int *)&this->f_2c) ? (*(unsigned int *)&this->f_28) : (*(unsigned int *)&this->f_2c);
    return (void*)(p);
}
