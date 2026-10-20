#include "compat/ptr.h"
struct Ctx_25370 {
    int pad[17];
    int Find(int);
};
struct Act_25370 {
    int pad;
    void Do(int);
};
struct Target_25370 {
    int* vt;
    int pad[2];
    int count;
    int items[1];
    void Run(int arg);
};
void Target_25370::Run(int arg) {
    int i = 0;
    while (i < count) {
        Ctx_25370* c = (Ctx_25370*)vt[17];
        hulk_intptr r = c->Find(items[i]);
        if (r)
            ((Act_25370*)r)->Do(arg);
        ++i;
    }
}
