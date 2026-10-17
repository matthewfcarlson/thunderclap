// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_0025f030 @ 0x0025f030
struct Link { Link *next; Link *owner; Link *up; };
struct Head { int unused; Link sentinel; };
struct Range { int unused; Link sentinel; };
void * __cdecl FUN_0025f030(Head *head, Range *range)
{
    Link *stop = &head->sentinel;
    Link *node = range->sentinel.owner;
    if (node != stop) {
        while (node->next != stop)
            node = node->next;
    } else {
        node = range->sentinel.up;
        while (node != stop && node->owner == &range->sentinel)
            node = node->up;
    }
    return node == stop ? 0 : (char *)node - 4;
}