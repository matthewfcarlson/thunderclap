#include "gen/core.h"

int __cdecl DoThing(int);

int core::CompletionEventRequest::vfunc_1() {
    DoThing(this->f_08);
    return 1;
}
