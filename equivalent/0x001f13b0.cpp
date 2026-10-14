// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 14/14)
// FUN_001f13b0 @ 0x001f13b0
struct Value {
    unsigned int data[2];
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027b040(void* value);
};
struct Key {
    Value elements[8];
    char extra[8];
    void FUN_001f0090(void* source);
};
struct Bucket;
struct Node {
    unsigned int a,b;
    Bucket* owner;
    Node* next;
    Value value;
};
struct Bucket { Node* first; };
extern void* __cdecl FUN_0008d710(unsigned int size, unsigned int kind);
struct Object {
    Bucket* FUN_001efb80(Key* key);
    void FUN_001f13b0(void* value, void* source);
};
void Object::FUN_001f13b0(void* value, void* source) {
    Key key;
    key.FUN_001f0090(source);
    Bucket* bucket = FUN_001efb80(&key);
    if (bucket) {
        Node* node = (Node*)FUN_0008d710(24, 6);
        if (node) {
            node->a = 0;
            node->b = 0;
            node->owner = 0;
            node->next = 0;
            node->value.FUN_0027af00();
        }
        node->value.FUN_0027b040(value);
        node->next = 0;
        node->owner = bucket;
        Node* tail = bucket->first;
        if (!tail) bucket->first = node;
        else {
            while (tail->next) tail = tail->next;
            tail->next = node;
        }
    }
    for (int i = 7; i >= 0; --i) key.elements[i].FUN_0027af50();
}
