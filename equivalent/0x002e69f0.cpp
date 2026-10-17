// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e69f0 @ 0x002e69f0
// equiv-conv: FUN_002e68a0 eax ecx edx
void FUN_002e68a0(void *result, void *source, void *other);
void __cdecl FUN_002e69a0(void *source, void *result);
void __cdecl FUN_002e69f0(void *source, void *other)
{
    char result[80];
    FUN_002e68a0(result, source, other);
    FUN_002e69a0(source, result);
}
