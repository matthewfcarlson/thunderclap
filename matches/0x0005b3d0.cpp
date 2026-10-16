// Same code shape as 0x0005a4c0 (propagated; names are from that function)
#include "gen/global.h"

struct A_5b3d0 {
    void* first();
};
struct B_5b3d0 {
    void* second();
};
struct Data_5b3d0 {
    char pad330[0x330];
    void* p330;
    void* p334;
};

void* CGrappleInvulnerableTrack::vfunc_11(int param) {
    if (param) {
        void* a = ((A_5b3d0*)param)->first();
        if (a) {
            void* b = ((B_5b3d0*)a)->second();
            if (b) {
                Data_5b3d0* d = (Data_5b3d0*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}
