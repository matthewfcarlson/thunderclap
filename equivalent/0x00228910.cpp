// STATUS: equivalent (tools/equiv.py level 3: 1011 inputs, branch coverage 6/6)
// FUN_00228910 @ 0x00228910
struct HeapEntry {
    int id;
    float key;
    int extra;
};

// Sift-up step of a binary min-heap (std::__push_heap): moves the hole from
// `hole` towards `top` while the parent's key is greater than the new key.
void FUN_00228910(HeapEntry* first, int hole, int top, HeapEntry value) {
    int parent = (hole - 1) / 2;
    while (top < hole && first[parent].key > value.key) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}
