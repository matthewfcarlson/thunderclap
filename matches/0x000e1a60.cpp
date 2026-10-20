#include "compat/ptr.h"
extern int vtFunction;
extern int vtAction;
extern void __cdecl thunk_FUN_00267090(void*);
class FEDoFunction {
  public:
    hulk_intptr vptr;
    int pad[13];
    int count;
    void** items;
    ~FEDoFunction();
};
FEDoFunction::~FEDoFunction() {
    vptr = (hulk_intptr)&vtFunction;
    if (items) {
        int i = 0;
        if (count > 0)
            do {
                void* p = items[i];
                if (p) {
                    thunk_FUN_00267090(p);
                    items[i] = 0;
                }
                ++i;
            } while (i < count);
        if (items) {
            thunk_FUN_00267090(items);
            items = 0;
        }
    }
    vptr = (hulk_intptr)&vtAction;
}