#include "gen/global.h"
struct CCameraDramaticTrack_6a470 {
    char pad[0x60];
};
struct Sub_6a470 {
    void Init();
};
struct CCameraDramaticTrack_nv_6a470 {
    void Finish();
};
extern int vCamera;
extern int vTrack;
void __fastcall Target(CCameraDramaticTrack_6a470* self) {
    *(int**)self = &vCamera;
    Sub_6a470* p = (Sub_6a470*)((char*)self + 0x60);
    int n = 8;
    do {
        p = (Sub_6a470*)((char*)p - 8);
        p->Init();
        --n;
    } while (n != 0);
    *(int**)self = &vTrack;
    ((CCameraDramaticTrack_nv_6a470*)(((CCameraDramaticTrack*)self)))->Finish();
}