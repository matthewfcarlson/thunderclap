// FUN_00226430 @ 0x00226430
struct HeapEntry_226430 {
    int id;
    float key;
    int extra;
};

// Sift-up step of a binary min-heap (std::__push_heap): moves the hole from
// `hole` towards `top` while the parent's key is greater than the new key.
void FUN_00226430(HeapEntry_226430* first, int hole, int top, HeapEntry_226430 value) {
    int parent = (hole - 1) / 2;
    while (top < hole && first[parent].key > value.key) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}
