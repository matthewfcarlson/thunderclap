struct Entry_1de140 {
    unsigned int a, b, c;
    float priority;
    unsigned short d, e;
};
Entry_1de140* __cdecl FUN_001de140(Entry_1de140* entries, int index, int limit, Entry_1de140 value) {
    int parent = (index - 1) / 2;
    while (limit < index) {
        if (!(entries[parent].priority < value.priority))
            break;
        entries[index].a = entries[parent].a;
        entries[index].b = entries[parent].b;
        entries[index].c = entries[parent].c;
        entries[index].priority = entries[parent].priority;
        entries[index].d = entries[parent].d;
        entries[index].e = entries[parent].e;
        index = parent;
        parent = (parent - 1) / 2;
    }
    entries[index].a = value.a;
    entries[index].b = value.b;
    entries[index].c = value.c;
    entries[index].priority = value.priority;
    entries[index].d = value.d;
    entries[index].e = value.e;
    return &entries[index];
}
