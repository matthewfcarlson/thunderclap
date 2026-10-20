// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 10/10)
// FUN_00215fa0 @ 0x00215fa0
struct Value { unsigned int kind; union { unsigned int bits; float number; } data; };
int __cdecl FUN_00215fa0(const Value *a, const Value *b)
{
    if (a->kind != b->kind) return 0;
    switch (a->kind) {
    case 0:
        return 1;
    case 3:
        return a->data.number == b->data.number;
    default:
        return a->data.bits == b->data.bits;
    }
}