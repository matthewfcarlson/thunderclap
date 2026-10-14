// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_002264b0 @ 0x002264b0
struct Item_2264b0 { unsigned int x, y, z; };
void __cdecl FUN_002264b0(Item_2264b0* first, Item_2264b0* middle, Item_2264b0* last)
{
    int step = middle - first;
    int count = last - first;
    int a = count, b = step;
    while (b != 0) { int r = a % b; a = b; b = r; }
    if (a >= count || a <= 0) return;
    Item_2264b0* start = first + a;
    for (int cycles = a; cycles != 0; --cycles, --start) {
        Item_2264b0 saved = *start;
        Item_2264b0* destination = start;
        Item_2264b0* source = start + step;
        if (source == last) source = first;
        while (source != start) {
            destination->x = source->x;
            destination->y = source->y;
            destination->z = source->z;
            int remaining = last - source;
            destination = source;
            if (step < remaining) source += step;
            else source = first + (step - remaining);
        }
        destination->x = saved.x;
        destination->y = saved.y;
        destination->z = saved.z;
    }
}
