// Same code shape as 0x0005a4c0 (propagated; names are from that function)
#include "gen/global.h"

struct A_5b230 {
    void* first();
};
struct B_5b230 {
    void* second();
};
struct Data_5b230 {
    char pad330[0x330];
    void* p330;
    void* p334;
};

void* CGrappleInvincibleTrack::vfunc_11(int param) {
    if (param) {
        void* a = ((A_5b230*)param)->first();
        if (a) {
            void* b = ((B_5b230*)a)->second();
            if (b) {
                Data_5b230* d = (Data_5b230*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}
