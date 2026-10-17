// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0021fcb0 @ 0x0021fcb0
struct Source { unsigned int value; };
struct Result { char pad0[0x14]; unsigned int data; char pad1[0x18]; int count; };
// equiv-conv: FUN_0021f8c0 eax ecx edx
void FUN_0021f8c0(int, int *, Source *);
void __cdecl FUN_0021f800(const char *);
unsigned int __cdecl FUN_0021add0(unsigned int, int, int, int);
// equiv-conv: FUN_0021f940 ecx edx eax stack
void FUN_0021f940(unsigned int, Source *, int, int);
// equiv-conv: FUN_0021fcb0 eax ebx
void FUN_0021fcb0(Source *source, Result *result) {
    int count;
    FUN_0021f8c0(4, &count, source);
    if (count < 0) FUN_0021f800("bad integer");
    result->data = FUN_0021add0(source->value, 0, 0, count * 4);
    result->count = count;
    FUN_0021f940(result->data, source, count, 4);
}
