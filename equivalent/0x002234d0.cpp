// STATUS: equivalent (tools/equiv.py level 3: 2974 inputs, branch coverage 16/16)
// FUN_002234d0 @ 0x002234d0
struct Elem_2234d0 {
    int w0, w1, w2;
    unsigned int minor;     // 0x0c
    unsigned int tail;      // 0x10
    int major;              // 0x14
    int rest[4];
};

void __cdecl FUN_00223110(Elem_2234d0 *first, int hole, int top, Elem_2234d0 value);

// true when the element at idx should be replaced by its left neighbour
static bool PreferLeft(const Elem_2234d0 &cur, const Elem_2234d0 &prev)
{
    if (cur.major > prev.major)
        return true;
    if (cur.major < prev.major)
        return false;
    if (cur.minor < prev.minor)
        return true;
    if (cur.minor > prev.minor)
        return false;
    return cur.tail > prev.tail;
}

void __cdecl FUN_002234d0(Elem_2234d0 *first, int top, int bottom, Elem_2234d0 value)
{
    int hole = top;
    int idx = 2 * top + 2;
    while (idx < bottom) {
        if (PreferLeft(first[idx], first[idx - 1]))
            idx--;
        first[hole] = first[idx];
        hole = idx;
        idx = 2 * idx + 2;
    }
    if (idx == bottom) {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    FUN_00223110(first, hole, top, value);
}
