// STATUS: equivalent (tools/equiv.py level 3: 15424 inputs, branch coverage 6/6)
// FUN_00220f80 @ 0x00220f80
// FUN_00220f80 @ 0x00220f80
struct Node { char pad[0x47]; unsigned char complexity; };
struct Context { Node *node; char pad04[8]; int errorContext; char pad10[0x14]; int count; };
void __cdecl FUN_0021b060(int context, const char *message);
// equiv-conv: FUN_00220e90 ebx esi edi
void FUN_00220e90(int *expression, int reg, Context *context);
// equiv-conv: FUN_00220f80 eax stack
void __cdecl FUN_00220f80(Context *context, int *expression)
{
    if (*expression != 11) {
        int next = context->count + 1;
        if (next > context->node->complexity) {
            if (next >= 250)
                FUN_0021b060(context->errorContext, "function or expression too complex");
            context->node->complexity = (unsigned char)next;
        }
        context->count = context->count + 1;
        FUN_00220e90(expression, context->count - 1, context);
    }
}
