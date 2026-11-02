extern "C" void __cdecl FUN_002feb70(unsigned int *, int, int, unsigned int);
extern "C" void FUN_002ff860(unsigned int* data, int index, int count, unsigned int value) {
    int orig = index;
    int child = index * 2 + 2;
    if (child < count) {
        do {
            unsigned int v = data[child];
            if (v < data[child - 1])
                --child;
            v = data[child];
            data[index] = v;
            index = child;
            child = child * 2 + 2;
        } while (child < count);
    }
    if (child == count) {
        data[index] = data[count - 1];
        index = count - 1;
    }
    FUN_002feb70(data, index, orig, value);
}
