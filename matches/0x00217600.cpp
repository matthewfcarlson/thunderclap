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
Output_217600* __cdecl Target(Input_217600* p, Output_217600* q) {
    if (p->type == 3)
        return (Output_217600*)p;
    if (p->type == 4) {
        float value;
        if (Fetch((char*)p->data + 0x10, &value)) {
            q->value = value;
            q->type = 3;
            return q;
        }
    }
    return 0;
}