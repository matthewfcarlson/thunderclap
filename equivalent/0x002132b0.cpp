// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 9/9)
// FUN_002132b0 @ 0x002132b0
struct Entry { int kind; int value; };
// equiv-conv: FUN_00212bb0 ecx edx
Entry *FUN_00212bb0(int second, int first);
int __cdecl FUN_002132b0(int first, int second)
{
    Entry *entry = FUN_00212bb0(second, first);
    switch (entry->kind) {
    case 2:
    case 7:
        entry = FUN_00212bb0(second, first);
        if (entry->kind == 2) return entry->value;
        if (entry->kind == 7) return entry->value + 16;
        break;
    case 5:
    case 6:
    case 8:
        return entry->value;
    }
    return 0;
}