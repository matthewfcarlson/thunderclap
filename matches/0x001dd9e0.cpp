class Node {
  public:
    char pad[0x11c];
    Node* next;
    unsigned int Check();
};
class Entry {
  public:
    char pad[0x18];
    Node* node;
    char pad2[6];
    short index;
    char pad3[4];
};
class Obj {
  public:
    char pad[0x608];
    Entry entries[0x800];
    unsigned char Target(int index);
};
unsigned char Obj::Target(int index) {
    if (index < 0 || index >= 0x800)
        return 0;
    Entry* e = &entries[index];
    int i = e->index + 0x104e;
    if ((*(unsigned char*)((char*)this + i * 0x14) & 1) && e->node && e->node->next)
        return e->node->next->Check();
    return 1;
}
