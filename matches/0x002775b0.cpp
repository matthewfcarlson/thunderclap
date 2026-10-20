struct Entry {
    char pad[0x64];
    Entry* next;
    int bucket;
};
struct Table {
    Entry* head[2];
    Entry* tail[2];
    void FUN_002775b0(Entry* entry);
};
void Table::FUN_002775b0(Entry* entry) {
    int bucket = entry->bucket;
    Entry* volatile* link = &head[bucket];
    Entry* previous = 0;
    if (*link) {
        do {
            Entry* cur = *link;
            if (cur == entry) {
                *link = (*link)->next;
                break;
            }
            link = &cur->next;
            previous = cur;
        } while (*link);
    }
    if (!*link)
        tail[bucket] = previous;
}