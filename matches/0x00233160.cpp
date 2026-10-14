class Node {
  public:
    virtual void Init();
    char pad04[0x10];
    void* owner;
    char pad18[8];
    Node* next;
};
class Container_233160 {
  public:
    char pad00[0x1c];
    Node* head;
    int Append(Node* node);
};
int Container_233160::Append(Node* node) {
    if (!node)
        return -1;
    int count = 0;
    Node* prev = 0;
    Node* cur = head;
    while (cur) {
        prev = cur;
        ++count;
        cur = cur->next;
    }
    if (prev)
        prev->next = node;
    else
        head = node;
    node->next = cur;
    node->owner = this;
    node->Init();
    return count;
}
