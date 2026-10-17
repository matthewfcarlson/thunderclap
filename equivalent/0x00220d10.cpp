// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00220d10 @ 0x00220d10
struct ContextData { char pad[8]; int value; };
struct Context { char pad0[12]; ContextData* data; char pad1[16]; int previous; };
int __cdecl FUN_00220b20(Context* context, unsigned int code, int value);
void __cdecl FUN_002207c0(Context* context, unsigned int* result, int previous);
// equiv-conv: FUN_00220d10 eax esi stack stack stack
unsigned int FUN_00220d10(unsigned int index, Context* context, unsigned int low, unsigned int middle, unsigned int high)
{
    unsigned int code = ((((index << 9) | middle) << 9 | high) << 6) | low;
    FUN_00220b20(context, code, context->data->value);
    int previous = context->previous;
    context->previous = -1;
    unsigned int result = FUN_00220b20(context, 0x7fff94, context->data->value);
    middle = result;
    FUN_002207c0(context, &middle, previous);
    return middle;
}