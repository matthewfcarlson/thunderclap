// STATUS: equivalent (tools/equiv.py level 3: 490 inputs, branch coverage 15/16, incomplete)
// FUN_00244810 @ 0x00244810
struct Link { Link* first; Link* second; };
struct Node { char reserved[0x30]; unsigned low; unsigned high; char reserved2[0x10]; Link link; };
struct List { Link* first; Link sentinel; };
struct Key { unsigned low; unsigned high; };
Node* __cdecl FUN_00244810(List* list, const Key* key)
{
    Link* current = list->first;
    while (current != &list->sentinel) {
        Node* node = (Node*)((char*)current - 0x48);
        if (key->high < node->high || (key->high == node->high && key->low < node->low)) {
            current = current->first;
        } else if (key->high == node->high && key->low == node->low) {
            return node;
        } else {
            current = current->second;
        }
    }
    return 0;
}