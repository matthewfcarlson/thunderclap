// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0021c240 @ 0x0021c240
struct FunctionInfo { char pad[0x3c]; int line; };
struct Context { FunctionInfo *function; char pad[8]; void *error; int message; };
int __cdecl FUN_00216320(int message, const char *format, ...);
void __cdecl FUN_0021afd0(void *error, int message, int zero);
// equiv-conv: FUN_0021c240 esi ecx edx
void FUN_0021c240(Context *context, int count, int kind)
{
    if (context->function->line == 0) {
        int message = FUN_00216320(context->message, "main function has more than %d %s", kind, count);
        FUN_0021afd0(context->error, message, 0);
    } else {
        int message = FUN_00216320(context->message, "function at line %d has more than %d %s", context->function->line, kind, count);
        FUN_0021afd0(context->error, message, 0);
    }
}