// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_00244cc0 @ 0x00244cc0
struct Link { Link* left; Link* parent; Link* right; };
struct Container { int unused; Link header; };
struct Iterator { char unused[8]; Link* link; };
void* __cdecl FUN_00244cc0(Container* container, Iterator* iterator)
{
    Link* const end = &container->header;
    Link* node = reinterpret_cast<Link*>(reinterpret_cast<char*>(iterator) + 4);
    Link* next = iterator->link;
    if (next != end) {
        while (next->left != end)
            next = next->left;
    } else {
        next = node->right;
        while (next != end && node == next->parent) {
            node = next;
            next = next->right;
        }
    }
    return next == end ? 0 : reinterpret_cast<char*>(next) - 4;
}
