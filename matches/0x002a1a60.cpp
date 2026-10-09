typedef char (__cdecl *Compare)(int, int);
void HeapPlace(int *a, int index, int limit, int value, Compare cmp)
{
    int parent = (index - 1) / 2;
    if (limit < index) {
        do {
            if (!cmp(a[parent], value)) break;
            a[index] = a[parent];
            index = parent;
            parent = (index - 1) / 2;
        } while (limit < index);
    }
    a[index] = value;
}