// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 19/20, incomplete)
// FUN_00261f90 @ 0x00261f90
struct Link { Link* next; };
struct Item { float value; Link link; };
// true when some item's value lies in the (possibly wrapping) interval (lo, hi]
bool __cdecl InRange(Link** head, float lo, float hi) {
    Link* l = *head;
    Item* item = l ? (Item*)((char*)l - 4) : 0;
    while (item) {
        float v = item->value;
        if (lo < hi) {
            if (lo < v && hi >= v) return true;
        } else if (lo > hi) {
            if (lo < v) {
                if (hi <= v) return true;
            } else if (hi >= v) {
                return true;
            }
        }
        l = item->link.next;
        item = l ? (Item*)((char*)l - 4) : 0;
    }
    return false;
}
