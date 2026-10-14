struct Key_1ef180 {
    __int64 value;
};
struct Node {
    __int64 value;
    int pad;
    Node* next;
    Node* Find(Key_1ef180*, char);
};
struct Table_1ef180 {
    Node* parents;
    Node* entries;
    Node* Find(Key_1ef180*, char);
};
Node* Table_1ef180::Find(Key_1ef180* key, char recurse) {
    Node* p = parents;
    Node* n = entries;
    Node* result = 0;
    while (n) {
        if (n->value == key->value)
            return n;
        n = n->next;
    }
    if (recurse) {
        while (p && !result) {
            result = p->Find(key, 1);
            p = p->next;
        }
    }
    return result;
}