// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 17/18, incomplete)
// FUN_00223190 @ 0x00223190
struct Item { unsigned int words[10]; };
void __cdecl FUN_00223190(Item* first, Item* middle, Item* last) {
    int shift = middle - first;
    int count = last - first;
    int a = count, b = shift;
    while (b != 0) { int r = a % b; a = b; b = r; }
    if (a >= count || a <= 0) return;
    Item* start = first + a;
    for (int cycles = a; cycles != 0; --cycles, --start) {
        Item saved = *start;
        Item* dest = start;
        Item* next = start + shift;
        if (next == last) next = first;
        while (next != start) {
            *dest = *next;
            dest = next;
            int remaining = last - next;
            if (shift < remaining) next += shift;
            else next = first + (shift - remaining);
        }
        *dest = saved;
    }
}
