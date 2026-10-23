// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// core::File::vfunc_19 @ 0x002761c0
#include "gen/core.h"


struct Context_2761c0 {
    void FUN_00272b60(::core::CompletionEventRequest* value, unsigned int state, unsigned int zero);
};
struct CompletionEventRequest_nv_2761c0 {
    ::core::CompletionEventRequest* FUN_00274ba0(unsigned int argument, Context_2761c0* context);
};
extern ::core::CompletionEventRequest* __cdecl FUN_00273560(unsigned int size);
namespace core {

}
void core::File::vfunc_19(int __p0) { unsigned int argument = (unsigned int)__p0;

    ::core::CompletionEventRequest* value = FUN_00273560(16);
    if (value)
        value = ((CompletionEventRequest_nv_2761c0*)(value))->FUN_00274ba0(argument, (*(Context_2761c0 * *)&this->f_0c));
    (*(Context_2761c0 * *)&this->f_0c)->FUN_00272b60(value, (*(unsigned int *)&this->f_10), 0);
}
