// STATUS: equivalent (tools/equiv.py level 3: 625 inputs, branch coverage 14/14)
// FUN_00223110 @ 0x00223110
struct Entry {
    int f0, f4, f8;
    unsigned int f0c;
    unsigned int f10;
    int f14;
    int rest[4];
};

// Sift-up of one element into a binary heap.
void FUN_00223110(Entry* heap, int index, int top, Entry item) {
    int parent = (index - 1) / 2;
    while (top < index) {
        Entry* p = &heap[parent];
        if (p->f14 < item.f14)
            break;
        if (p->f14 == item.f14) {
            if (p->f0c > item.f0c)
                break;
            if (p->f0c == item.f0c && p->f10 <= item.f10)
                break;
        }
        heap[index] = *p;
        index = parent;
        parent = (index - 1) / 2;
    }
    heap[index] = item;
}
