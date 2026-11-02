// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6a20 @ 0x002e6a20
struct Data { char bytes[80]; };
// equiv-conv: FUN_002e68a0 eax ecx edx
extern "C" void __cdecl FUN_002e68a0(char *, void *, const char *);
void __cdecl FUN_002e69d0(void* object, Data* result);
extern "C" void __cdecl FUN_002e6a20(void* object, void* value)
{
    Data result;
    FUN_002e68a0((char *)(Data *)(&result), object, (const char *)(void *)value);
    FUN_002e69d0(object, &result);
}
