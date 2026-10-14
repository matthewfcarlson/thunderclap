struct Lock_272fc0 {
    virtual void enter();
    virtual void leave();
};
struct Node {
    unsigned int data;
    Node* next;
};
struct Event_272fc0 {
    unsigned int value;
};
void __cdecl FUN_0026d8a0(Event_272fc0*);
struct Queue_272fc0 {
    char pad0[12];
    Lock_272fc0 lock;
    char pad1[0x68 - 0x10];
    Event_272fc0 event;
    Node* heads[3];
    Node* tails[3];
    char pad2[8];
    unsigned int count;
    void FUN_00272fc0(Node* node, int index, char front);
};
void Queue_272fc0::FUN_00272fc0(Node* node, int index, char front) {
    lock.enter();
    if (front) {
        if (!tails[index])
            tails[index] = node;
        node->next = heads[index];
        heads[index] = node;
    } else {
        if (!heads[index])
            heads[index] = node;
        else
            tails[index]->next = node;
        node->next = 0;
        tails[index] = node;
    }
    ++count;
    lock.leave();
    FUN_0026d8a0(&event);
}
