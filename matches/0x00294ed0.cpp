class Search {
  public:
    char pad0[0x38];
    int count;
    char pad3c[4];
    unsigned short* values;
    int Find(unsigned short key);
};
int Search::Find(unsigned short key) {
    int low = 0;
    int high = count - 1;
    if (high >= 0) {
        do {
            int mid = (high + low) >> 1;
            unsigned short value = values[mid];
            if (key == value)
                return mid;
            if (key < value)
                high = mid - 1;
            else
                low = mid + 1;
        } while (low <= high);
    }
    return -1;
}