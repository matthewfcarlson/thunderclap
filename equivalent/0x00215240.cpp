// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00215240 @ 0x00215240
struct ErrorValue { int kind; int detail; };
struct ErrorContext { char pad[8]; ErrorValue* next; };
int __cdecl FUN_00219430(ErrorContext*, const char*, int);
// equiv-conv: FUN_00215240 eax ecx edi
void FUN_00215240(int code, ErrorValue* output, ErrorContext* context)
{
    if (code == 1 || code == 3) {
        *output = context->next[-1];
    } else if (code == 4) {
        output->detail = FUN_00219430(context, "not enough memory", 0x11);
        output->kind = 4;
    } else if (code == 5) {
        output->detail = FUN_00219430(context, "error in error handling", 0x17);
        output->kind = 4;
    }
    context->next = output + 1;
}