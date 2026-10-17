// STATUS: equivalent (tools/equiv.py level 3: 2982 inputs, branch coverage 8/8)
// FUN_00216e10 @ 0x00216e10
struct Entries {
    int *items;
    int auxiliary;
    int count;
    char unused[0x18];
    int index;
};
struct Context {
    char unused[0x10];
    Entries *entries;
};
extern "C" void __cdecl FUN_002171c0(Context *, int *, int, int *, int *);
// equiv-conv: FUN_00216e10 stack stack ebx
int __cdecl FUN_00216e10(int value, int remaining, Context *context)
{
    Entries *entries = context->entries;
    int index = entries->index;
    while (index < entries->count) {
        int *item = &context->entries->items[index];
        int amount = 0x7fffffff;
        if (*item != 0)
            FUN_002171c0(context, item, value, &amount, &entries->auxiliary);
        remaining += amount - 0x7fffffff;
        if (remaining <= 0)
            break;
        ++index;
    }
    entries->index = index + 1;
    return remaining;
}