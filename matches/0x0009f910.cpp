void __cdecl FUN_0009f910(int count, float* keys, unsigned int* values) {
    int gap = 1;
    int limit = count / 9;
    while (gap <= limit)
        gap = gap * 3 + 1;
    while (gap > 0) {
        for (int i = gap; i < count; ++i) {
            float key = keys[i];
            unsigned int value = values[i];
            int j = i;
            while (j >= gap && key < keys[j - gap]) {
                keys[j] = keys[j - gap];
                values[j] = values[j - gap];
                j -= gap;
            }
            keys[j] = key;
            values[j] = value;
        }
        gap /= 3;
    }
}