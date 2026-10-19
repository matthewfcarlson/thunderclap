// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// FUN_0021faf0 @ 0x0021faf0
// FUN_0021faf0 @ 0x0021faf0
struct Source { int data; };
struct Destination { char pad0[12]; int data; char pad1[28]; int count; };
// equiv-conv: FUN_0021f8c0 ecx eax edx
void FUN_0021f8c0(int *result, int kind, Source *source);
// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(Source *source, const char *message);
int __cdecl FUN_0021add0(int data, int a, int b, int bytes);
// equiv-conv: FUN_0021f940 eax ecx edx stack
void FUN_0021f940(int count, int data, Source *source, int kind);
// equiv-conv: FUN_0021faf0 eax ebx
void FUN_0021faf0(Source *source, Destination *destination)
{
    int count;
    FUN_0021f8c0(&count, 4, source);
    if (count < 0)
        FUN_0021f800(source, "bad integer");
    destination->data = FUN_0021add0(source->data, 0, 0, count * 4);
    destination->count = count;
    FUN_0021f940(count, destination->data, source, 4);
}
