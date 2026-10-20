#include "compat/ptr.h"
struct ThisWrap_001e9a90 {
    hulk_intptr GetThing(int);
    void FUN_001e9a90(int a, unsigned int b);
};
int CheckThing();
void ApplyThing(int, int, float);
struct Obj_1e9a90 {
    char pad[12];
    int value;
    void Reset(int);
};
extern Obj_1e9a90* gCurrent;
void ThisWrap_001e9a90::FUN_001e9a90(int a, unsigned int b) {
    Obj_1e9a90* p = (Obj_1e9a90*)this->GetThing(a);
    if (p && p != gCurrent) {
        if (gCurrent)
            gCurrent->Reset(b);
        if (CheckThing()) {
            int y = CheckThing();
            ApplyThing(y, p->value, (float)b);
        }
        gCurrent = p;
    }
}