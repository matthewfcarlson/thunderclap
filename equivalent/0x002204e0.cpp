// STATUS: equivalent (tools/equiv.py level 3: 2933 inputs, branch coverage 2/2)
// FUN_002204e0 @ 0x002204e0
struct ControlWords { char pad[12]; unsigned int *words; };
struct Control { ControlWords *data; char pad[8]; void *owner; };
void __cdecl FUN_0021b060(void *, const char *);
// equiv-conv: FUN_002204e0 eax ecx ebx
void FUN_002204e0(int end, int start, Control *control)
{
    unsigned int length = (unsigned int)end - (unsigned int)start - 1;
    int signedLength = (int)length;
    unsigned int magnitude = signedLength < 0 ? 0u - length : length;
    unsigned int *word = &control->data->words[start];
    if ((int)magnitude > 0x1ffff)
        FUN_0021b060(control->owner, "control structure too long");
    unsigned int oldValue = *word;
    unsigned int bits = (length + 0x1ffff) << 6;
    *word = oldValue ^ ((bits ^ oldValue) & 0xffffc0);
}