// FUN_002775b0 @ 0x002775b0
// (x64t13) the drive's library list unlink (src/engine/core/CementLibrary.cpp, records.h CoreCementLibrary): the bucket annotated HULK_RANGE(0, 1) is drawn from the two lists (without it most inputs index outside the list and are not used, and an index into a neighbouring object lets the 64-bit run follow other garbage)
#if defined(HULK_EQ64_PARSE)
#define HULK_RANGE(lo, hi) __attribute__((annotate("hulk_range " #lo " " #hi)))
#else
#define HULK_RANGE(lo, hi)
#endif
struct Entry {
    void* words[25];
    Entry* next;
    int bucket HULK_RANGE(0, 1);            // +0x68 the list it is on (as records.h: 0x00277570 indexes by it)
    void* callback;
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
                *link = (Entry*)(*link)->next;
                break;
            }
            link = (Entry* volatile*)&cur->next;
            previous = cur;
        } while (*link);
    }
    if (!*link)
        tail[bucket] = previous;
}
