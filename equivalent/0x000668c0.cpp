// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000668c0 @ 0x000668c0
struct Item { char unused[16]; float value; };
int __cdecl FUN_000668c0(const Item *a, const Item *b)
{
    if (a->value < b->value) return -1;
    if (b->value < a->value) return 1;
    return 0;
}