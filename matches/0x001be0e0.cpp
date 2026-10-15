struct Key {
    int a, b;
};
class Table {
  public:
    char pad[0x3c];
    struct Entry {
        __int64 key;
        char pad[16];
    }* items;
    int count;
    int Find(Key k);
};
int Table::Find(Key k) {
    int result = -1;
    for (int i = 0; i < count; i++) {
        if (items[i].key == *(__int64*)&k) {
            result = i;
            break;
        }
    }
    return result;
}