// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 8/8)
// FUN_00273140 @ 0x00273140
struct Lock_273140 {
    virtual void acquire();
    virtual void release();
};
struct Node {
    unsigned int value;
    Node* next;
};
struct Queue_273140 {
    char reserved0[12];
    Lock_273140 lock;
    char reserved1[92];
    Node* heads[3];
    Node* tails[3];
    Node* FUN_00273140(unsigned int* index);
};
Node* Queue_273140::FUN_00273140(unsigned int* index) {
    lock.acquire();
    Node* result = 0;
    for (unsigned int i = 0; i < 3; ++i) {
        if (heads[i]) {
            result = heads[i];
            if (result == tails[i]) tails[i] = 0;
            heads[i] = result->next;
            result->next = 0;
            if (index) *index = i;
            break;
        }
    }
    lock.release();
    return result;
}
