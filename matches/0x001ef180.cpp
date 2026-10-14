struct Key {
    __int64 value;
};
struct Node {
    __int64 value;
    int pad;
    Node* next;
    Node* Find(Key*, char);
};
struct Table {
    Node* parents;
    Node* entries;
    Node* Find(Key*, char);
};
Node* Table::Find(Key* key, char recurse) {
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