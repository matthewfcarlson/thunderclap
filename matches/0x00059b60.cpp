struct Entry {
    int id;
    char pad[32];
};
class Pool {
  public:
    int count;
    unsigned capacity;
    Entry* entries;
    char* used;
    int Allocate();
};
int Pool::Allocate() {
    int result = 0;
    for (unsigned i = 0; i < capacity; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            result = count;
            entries[i].id = result;
            ++count;
            break;
        }
    }
    return result;
}