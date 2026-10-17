// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001dff30 @ 0x001dff30
typedef unsigned int Word;
typedef unsigned char Byte;
struct Context {};
typedef Byte (__stdcall *Callback)(Word, Word, Word, Word, Word);
void __cdecl FUN_001dff30(Context* context, const Word* values, Byte* result, Callback callback)
{
    Byte value = callback(values[0], values[1], values[2], values[3], values[4]);
    if (result) *result = value;
}
