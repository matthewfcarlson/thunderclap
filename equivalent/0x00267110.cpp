// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 7/8, incomplete)
// FUN_00267110 @ 0x00267110
struct Object { virtual void unused(); virtual void FUN_00000000(); };
struct Entry;
struct List { char pad[4]; Entry* head; };
struct Entry { Object* object; unsigned int value; Entry* next; List* list; };
extern Entry DAT_00527c60[];
extern Object* DAT_00527f58;
void __cdecl FUN_00267110(unsigned int index) {
    Entry* entry = &DAT_00527c60[index];
    List* list = entry->list;
    Entry* current = list->head;
    Entry* previous = 0;
    if (!current) return;
    while (current != entry) {
        previous = current;
        current = current->next;
        if (!current) return;
    }
    if (previous) previous->next = entry->next;
    else list->head = entry->next;
    entry->object->FUN_00000000();
    entry->object = DAT_00527f58;
    entry->value = 0;
    entry->list = 0;
    entry->next = 0;
}
