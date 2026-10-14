// STATUS: equivalent (tools/equiv.py level 3: 2966 inputs, branch coverage 6/6)
// FUN_001de140 @ 0x001de140
struct Elem {
    int a, b, c;
    float key;               // 0xc
    short s0, s1;            // 0x10
};

// std::__push_heap step: sift `value` up from `hole` towards `top`
void __cdecl FUN_001de140(Elem *first, int hole, int top, Elem value)
{
    int parent = (hole - 1) / 2;
    while (top < hole && first[parent].key < value.key) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}
