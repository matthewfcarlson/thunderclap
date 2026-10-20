#include "gen/physics.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CollisionAnalyser_nv_2f7e50 {
    void* init();
};
struct Obj_2f7e50 {
    char pad[8];
    void* member;
};
void __fastcall FUN_002f7e50(Obj_2f7e50* self) {
    if (self->member == 0) {
        void* p = FUN_0008d690(0x6c);
        void* r;
        if (p != 0) {
            r = ((CollisionAnalyser_nv_2f7e50*)(((physics::CollisionAnalyser*)p)))->init();
        } else {
            r = 0;
        }
        self->member = r;
    }
}
