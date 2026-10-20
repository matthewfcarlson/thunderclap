typedef unsigned __int64 U64;
extern U64 __cdecl FUN_0027b020(unsigned int value);
struct Object {
    void FUN_000ce5c0(unsigned int first, U64 result, unsigned int last);
    void FUN_000ce700(unsigned int first, unsigned int value, unsigned int last);
};
void Object::FUN_000ce700(unsigned int first, unsigned int value, unsigned int last) {
    if (value)
        FUN_000ce5c0(first, FUN_0027b020(value), last);
    else
        FUN_000ce5c0(first, 0, last);
}