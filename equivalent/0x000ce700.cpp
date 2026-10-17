// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000ce700 @ 0x000ce700
typedef unsigned __int64 U64;
extern U64 __cdecl FUN_0027b020(unsigned int value, unsigned int mode);
struct Object {
    void FUN_000ce5c0(unsigned int first, unsigned int low, unsigned int high, unsigned int last);
    void FUN_000ce700(unsigned int first, unsigned int value, unsigned int last);
};
void Object::FUN_000ce700(unsigned int first, unsigned int value, unsigned int last)
{
    if (value) {
        U64 result = FUN_0027b020(value, last);
        FUN_000ce5c0(first, (unsigned int)result, (unsigned int)(result >> 32), last);
    } else {
        FUN_000ce5c0(first, 0, 0, last);
    }
}