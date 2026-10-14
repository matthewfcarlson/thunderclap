// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_19 @ 0x002761c0
struct Allocated_2761c0;
struct Context {
    void FUN_00272b60(Allocated_2761c0* value, unsigned int state, unsigned int zero);
};
struct Allocated_2761c0 {
    Allocated_2761c0* FUN_00274ba0(unsigned int argument, Context* context);
};
extern Allocated_2761c0* __cdecl FUN_00273560(unsigned int size);
namespace core {
struct File {
    void* primaryVtable;
    void* secondaryVtable;
    unsigned int reserved;
    Context* context;
    unsigned int state;
    void vfunc_19(unsigned int argument);
};
void File::vfunc_19(unsigned int argument) {
    Allocated_2761c0* value = FUN_00273560(16);
    if (value)
        value = value->FUN_00274ba0(argument, context);
    context->FUN_00272b60(value, state, 0);
}
}
