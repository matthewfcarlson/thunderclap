// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_002775b0 @ 0x002775b0
struct Entry { char pad[0x64]; Entry* next; int bucket; };
struct Table { Entry* head[2]; Entry* tail[2]; void FUN_002775b0(Entry* entry); };
void Table::FUN_002775b0(Entry* entry) {
    int bucket = entry->bucket;
    Entry** link = &head[bucket];
    Entry* previous = 0;
    if (*link) {
        while (*link != entry) {
            previous = *link;
            link = &previous->next;
            if (!*link) break;
        }
        if (*link == entry) *link = entry->next;
        if (*link) return;
    }
    tail[bucket] = previous;
}