// (recs1) content's load-request arguments, out of records.h (which includes this) for the callers of the loader
// 0x00265810 that fill them on their stack (find1 F14: their 32-bit views put the kind 8 bytes early natively, where
// the loading fiber read a stack word as its heap id). Declare no namespaces here.
#ifndef HULK_DECLS_CONTENT_LOAD_H
#define HULK_DECLS_CONTENT_LOAD_H

// A load request's arguments (x64t13): what the caller fills on its stack (FUN_001bc0c0's frame) and hands to the
// loader's 0x00265810, which copies them into the content::LoadRequest it allocates (its constructor 0x00266890 copies
// the 0x110 bytes whole). The file's path, the context 0x00266850 stores in the request, the completion callback
// (the constructor calls its slot 0, the destructor 0x00266690 releases it), the kind and the wait flag (0x00265810
// polls the request until it is done when it is set).
struct ContentLoadArgs {
    char path[0x100];                       // +0x000
    void* context;                          // +0x100
    void* callback;                         // +0x104
    int kind;                               // +0x108 (0xb from FUN_001bc0c0)
    unsigned char wait;                     // +0x10c
    char pad10d[3];                         // +0x10d
};

#endif
