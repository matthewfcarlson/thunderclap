// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_00228990 @ 0x00228990
struct Item_228990 { unsigned int a, b, c; };
void __cdecl FUN_00228990(Item_228990* first, Item_228990* middle, Item_228990* last)
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
    Item_228990* start = first + a;
    for (int cycles = a; cycles != 0; --cycles, --start) {
        Item_228990 saved = *start;
        Item_228990* destination = start;
        Item_228990* source = start + shift;
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
