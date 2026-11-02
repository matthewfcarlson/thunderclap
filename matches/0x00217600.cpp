#include "compat/ptr.h"
extern "C" int __cdecl Fetch(void* p, float* out);
struct Input_217600 {
    int type;
    hulk_intptr data;
};
struct Output_217600 {
    int type;
    float value;
};
extern "C" void * __cdecl FUN_00217600(void * p, void * q) {
    if (((Input_217600 *)p)->type == 3)
        return (Output_217600 *)((Output_217600*)((Input_217600 *)p));
    if (((Input_217600 *)p)->type == 4) {
        float value;
        if (Fetch((char*)((Input_217600 *)p)->data + 0x10, &value)) {
            ((Output_217600 *)q)->value = value;
            ((Output_217600 *)q)->type = 3;
            return (Output_217600 *)((Output_217600 *)q);
        }
    }
    return (Output_217600 *)0;
}