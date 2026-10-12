// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026b2f0 @ 0x0026b2f0
extern "C" char __cdecl FUN_00271820(const char*, int*, const char**, void*);
extern "C" int __cdecl FUN_00271870(const char*, char*, int, void*, int*, void*);
// equiv-conv: FUN_0026b2f0 eax ecx stack stack stack
int __cdecl FUN_0026b2f0(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271820(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271870(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}
