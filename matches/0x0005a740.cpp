// Same code shape as 0x0005a4c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct A_5a740 {
    void* first();
};
struct B_5a740 {
    void* second();
};
struct Data_5a740 {
    char pad330[0x330];
    void* p330;
    void* p334;
};

void* CGrappleAutoTargetTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((A_5a740*)param)->first();
        if (a) {
            void* b = ((B_5a740*)a)->second();
            if (b) {
                Data_5a740* d = (Data_5a740*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}
