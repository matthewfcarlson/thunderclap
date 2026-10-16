#include "gen/Render.h"

extern "C" void* __cdecl memcpy(void*, const void*, unsigned);

void Render::Object::vfunc_6(int a0, int , int , int , int , int , int , int , int , int , int , int , int , int , int , int ) {
    memcpy((char*)this + 0x30, &a0, 0x40);
}
