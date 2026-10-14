typedef unsigned int uint_219610;
struct Owner_219610;
void* Alloc(Owner_219610*, int, int, int);
struct Owner_219610 {
    char pad[0x10];
    void* source;
    char pad2[0x34];
    void* list;
};
struct Node {
    Node* next;
    char data[4];
    uint_219610 key;
};
void FUN_00219610(Owner_219610* self, uint_219610 key) {
    Node* current = (Node*)self->list;
    Node** link = (Node**)&self->list;
    while (current != 0 && current->key >= key) {
        if (current->key == key)
            return;
        link = &current->next;
        current = current->next;
    }
    Node* node = (Node*)Alloc(self, 0, 0, 0x14);
    ((char*)node)[4] = 10;
    ((char*)node)[5] = *((char*)self->source + 0x14);
    node->key = key;
    node->next = *link;
    *link = node;
}