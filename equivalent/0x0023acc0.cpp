// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0023acc0 @ 0x0023acc0
struct Node {
    char text[0x100];
    Node* next;           // 0x100
};
struct Entry {
    int type;
    Node* head;           // 0x04
    char pad08[0x18 - 8];
};
struct Table {
    char pad00[0x12c];
    int count;            // 0x12c
    char pad130[8];
    Entry entries[1];     // 0x138
    bool TotalLength(int index, int* total);
};

bool Table::TotalLength(int index, int* total)
{
    if (index < 0 || index >= count)
        return false;
    if (entries[index].type != 4)
        return false;
    *total = 0;
    for (Node* n = entries[index].head; n != 0; n = n->next) {
        const char* p = n->text;
        while (*p)
            p++;
        *total = *total + (int)(p - n->text);
    }
    return true;
}
