// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 7/8, incomplete)
// FUN_00267110 @ 0x00267110
struct Object { virtual void unused(); virtual void FUN_00000000(); };
struct Entry_267110;
struct List_267110 { char pad[4]; Entry_267110* head; };
struct Entry_267110 { Object* object; unsigned int value; Entry_267110* next; List_267110* list; };
extern Entry_267110 DAT_00527c60[];
extern Object* DAT_00527f58;
void __cdecl FUN_00267110(unsigned int index) {
    Entry_267110* entry = &DAT_00527c60[index];
    List_267110* list = entry->list;
    Entry_267110* current = list->head;
    Entry_267110* previous = 0;
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
