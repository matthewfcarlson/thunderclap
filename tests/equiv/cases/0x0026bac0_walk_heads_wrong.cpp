struct Bucket {
    int unused;
    unsigned int size;
    Bucket *next;
};

struct Chunk {
    int unused[1];
    unsigned int size;
    int unused2;
    Chunk *next;
};

struct Heap {
    char pad00[4];
    Bucket *buckets[10];
    Chunk *first;
    char pad30[4];
    Chunk bins[1];          // 127 bins, 8 bytes apart (the +0xc link overlaps the next bin)
    char pad44[0x464 - 0x44];
    int f464;
};

struct HeapStats {
    int f464;
    int chunks;
    int bucketCount;
    int f450;
    int f460;
    int f470;
    int bucketBytes;
    int freeBytes;
    int totalBytes;
    unsigned int firstSize;
};

extern Heap *DAT_0052839c;
extern void __cdecl FUN_0026b970(Heap *heap);

HeapStats FUN_0026bac0()
{
    Heap *heap = DAT_0052839c;
    if (!heap->first)
        FUN_0026b970(heap);
    unsigned int firstSize = heap->first->size & ~3u;

    int bucketCount = 0;
    int bucketBytes = 0;
    for (int i = 0; i < 10; i++) {
        for (Bucket *b = heap->buckets[i]; b; b = b->next) {
            bucketCount++;
            bucketBytes += b->size & ~3u;
        }
    }
    int total = firstSize + bucketBytes;
    int chunks = 1;
    for (int i = 0; i < 0x7f; i++) {
        Chunk *bin = (Chunk *)((char *)heap + 0x34 + 8 * i);
        for (Chunk *c = bin->next; c != bin; c = c->next) {
            chunks += 2;
            total += c->size & ~3u;
        }
    }
    HeapStats stats;
    stats.f464 = heap->f464;
    stats.freeBytes = stats.f464 - total;
    stats.f450 = *(int *)((char *)heap + 0x450);
    stats.totalBytes = total;
    stats.f460 = *(int *)((char *)heap + 0x460);
    stats.f470 = *(int *)((char *)heap + 0x470);
    stats.bucketBytes = bucketBytes;
    stats.bucketCount = bucketCount;
    stats.chunks = chunks;
    stats.firstSize = firstSize;
    return stats;
}
