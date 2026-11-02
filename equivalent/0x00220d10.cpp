// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00220d10 @ 0x00220d10
struct ContextData { char pad[8]; int value; };
struct Context { char pad0[12]; ContextData* data; char pad1[16]; int previous; };
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
void __cdecl FUN_002207c0(Context* context, unsigned int* result, int previous);
// equiv-conv: FUN_00220d10 eax esi stack stack stack
extern "C" unsigned int FUN_00220d10(unsigned int index, void * context, unsigned int low, unsigned int middle, unsigned int high)
{
    unsigned int code = ((((index << 9) | middle) << 9 | high) << 6) | low;
    FUN_00220b20((Context *)((Context *)context), code, (int)(((Context *)context)->data->value));
    int previous = ((Context *)context)->previous;
    ((Context *)context)->previous = -1;
    unsigned int result = FUN_00220b20((Context *)((Context *)context), 0x7fff94, (int)(((Context *)context)->data->value));
    middle = result;
    FUN_002207c0(((Context *)context), &middle, previous);
    return middle;
}