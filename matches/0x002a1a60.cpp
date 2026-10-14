typedef char(__cdecl* Compare_2a1a60)(int, int);
void HeapPlace(int* a, int index, int limit, int value, Compare_2a1a60 cmp) {
    int parent = (index - 1) / 2;
    if (limit < index) {
        do {
            if (!cmp(a[parent], value))
                break;
            a[index] = a[parent];
            index = parent;
            parent = (index - 1) / 2;
        } while (limit < index);
    }
    a[index] = value;
}