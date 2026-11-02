// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 10/10)
// FUN_00215fa0 @ 0x00215fa0
struct Value { unsigned int kind; union { unsigned int bits; float number; } data; };
extern "C" int __cdecl FUN_00215fa0(const void *a, const void *b)
{
    if (((const Value *)a)->kind != ((const Value *)b)->kind) return 0;
    switch (((const Value *)a)->kind) {
    case 0:
        return 1;
    case 3:
        return ((const Value *)a)->data.number == ((const Value *)b)->data.number;
    default:
        return ((const Value *)a)->data.bits == ((const Value *)b)->data.bits;
    }
}