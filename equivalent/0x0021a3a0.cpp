// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0021a3a0 @ 0x0021a3a0
void __cdecl FUN_00219a60(void* object, unsigned* second, unsigned* first);
unsigned __cdecl FUN_00215f70(unsigned value);
// equiv-conv: FUN_0021a0f0 eax ecx stack stack stack
void FUN_0021a0f0(unsigned second, void* object, unsigned argument, unsigned length, unsigned first);
// equiv-conv: FUN_0021a3a0 esi stack
void FUN_0021a3a0(void* object, unsigned argument)
{
    unsigned first;
    unsigned second;
    FUN_00219a60(object, &second, &first);
    unsigned length = FUN_00215f70(first);
    FUN_0021a0f0(second, object, argument, length + 1, first);
}
