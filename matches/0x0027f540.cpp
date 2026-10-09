unsigned char Find(int value, int* array, int count) {
    int i = 0;
    if (count > 0) {
        do {
            if (value == array[i])
                return 1;
            ++i;
        } while (i < count);
    }
    return 0;
}