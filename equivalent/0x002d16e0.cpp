// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d16e0 @ 0x002d16e0
struct Color { char pad[12]; unsigned int value; char pad2[8]; unsigned char alpha; };
struct Palette { char pad[40]; signed char *entries; };
struct Context { char pad[444]; Palette *palette; };
unsigned int * __cdecl FUN_002e6840(Color **color, unsigned int value, unsigned int alpha);
void __cdecl FUN_002d16e0(int unused, int index, Context *context, Color *color)
{
    Color *original = color;
    unsigned int value = ((unsigned int)(int)context->palette->entries[index] << 24) | (original->value & 0xffffff);
    original->value = value;
    unsigned int *result = FUN_002e6840(&color, value, original->alpha);
    original->value = *result;
}