struct Lock {
    virtual void enter();
    virtual void leave();
};
struct Node {
    unsigned int data;
    Node* next;
};
struct Event {
    unsigned int value;
};
void __cdecl FUN_0026d8a0(Event*);
struct Queue {
    char pad0[12];
    Lock lock;
    char pad1[0x68 - 0x10];
    Event event;
    Node* heads[3];
    Node* tails[3];
    char pad2[8];
    unsigned int count;
    void FUN_00272fc0(Node* node, int index, char front);
};
void Queue::FUN_00272fc0(Node* node, int index, char front) {
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
