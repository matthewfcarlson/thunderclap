// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1680 @ 0x002d1680
struct Indices { char pad[0x24]; unsigned int *values; };
struct Source { char pad[0x1bc]; Indices *indices; };
struct Destination { char pad0[0xc]; unsigned int value; char pad1[0x2e]; unsigned char flag; };
unsigned int* __cdecl FUN_002e6780(Source **source, unsigned int color, unsigned int flag);
void __cdecl FUN_002d1680(void *unused, unsigned int index, Source *source, Destination *destination)
{
    unsigned int color = (source->indices->values[index] & 0xffffff) | (destination->value & 0xff000000);
    destination->value = *FUN_002e6780(&source, color, destination->flag);
}