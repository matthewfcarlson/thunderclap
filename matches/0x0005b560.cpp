// Same code shape as 0x0005a4c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

struct A_5b560 {
};
struct B_5b560 {
    void* second();
};
struct Data_5b560 {
    char pad330[0x330];
    void* p330;
    void* p334;
};

void* CGrappleSoundTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b560*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b560*)a)->second();
            if (b) {
                Data_5b560* d = (Data_5b560*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}
