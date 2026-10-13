// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_00228990 @ 0x00228990
struct Item { unsigned int a, b, c; };
void __cdecl FUN_00228990(Item* first, Item* middle, Item* last)
{
    int shift = middle - first;
    int count = last - first;
    int a = count;
    int b = shift;
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    if (a >= count || a <= 0) return;
    Item* start = first + a;
    for (int cycles = a; cycles != 0; --cycles, --start) {
        Item saved = *start;
        Item* destination = start;
        Item* source = start + shift;
        if (source == last) source = first;
        while (source != start) {
            destination->a = source->a;
            destination->b = source->b;
            destination->c = source->c;
            int remaining = last - source;
            destination = source;
            if (shift < remaining) source += shift;
            else source = first + (shift - remaining);
        }
        destination->a = saved.a;
        destination->b = saved.b;
        destination->c = saved.c;
    }
}
