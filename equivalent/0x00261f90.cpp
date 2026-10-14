// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 19/20, incomplete)
// FUN_00261f90 @ 0x00261f90
struct Link_261f90 { Link_261f90* next; };
struct Item_261f90 { float value; Link_261f90 link; };
// true when some item's value lies in the (possibly wrapping) interval (lo, hi]
bool __cdecl InRange(Link_261f90** head, float lo, float hi) {
    Link_261f90* l = *head;
    Item_261f90* item = l ? (Item_261f90*)((char*)l - 4) : 0;
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
        item = l ? (Item_261f90*)((char*)l - 4) : 0;
    }
    return false;
}
