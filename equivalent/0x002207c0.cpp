// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 7/8, incomplete)
// FUN_002207c0 @ 0x002207c0
struct NodeList { char pad[12]; unsigned int *entries; };
// equiv-conv: FUN_002204e0 eax ecx ebx
void FUN_002204e0(int item, int index, NodeList **list);
void __cdecl FUN_002207c0(NodeList **list, int *head, int item)
{
    if (item == -1) return;
    int index = *head;
    if (index == -1) {
        *head = item;
        return;
    }
    unsigned int *entries = (*list)->entries;
    for (;;) {
        int offset = ((entries[index] >> 6) & 0x3ffff) - 0x1ffff;
        if (offset == -1) break;
        index += offset + 1;
        if (index == -1) break;
    }
    FUN_002204e0(item, index, list);
    volatile int barrier = 0;
    (void)barrier;
}