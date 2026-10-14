// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_00295520 @ 0x00295520
struct Resource {
    virtual void unused();
    virtual void release();
};
struct FontEntry {
    char data[0x28];
    void FUN_002c3ac0();
};
struct ArrayHeader { unsigned count; };
void __cdecl FUN_0008d340(void*);
namespace pure3d {
struct TextureFont {
    virtual ~TextureFont();
    char padding[0x24];
    Resource* resource;
    unsigned resourceCount;
    Resource** resources;
    char padding34[8];
    FontEntry* entries;
    void* allocation;
    void FUN_0027afd0();
};
TextureFont::~TextureFont() {
    if (resource) {
        resource->release();
        resource = 0;
    }
    for (unsigned i = 0; i < resourceCount; ++i) {
        Resource** slot = resources + i;
        if (*slot) {
            (*slot)->release();
            *slot = 0;
        }
    }
    FUN_0008d340(resources);
    if (entries) {
        ArrayHeader* header = reinterpret_cast<ArrayHeader*>(entries) - 1;
        unsigned count = header->count;
        FontEntry* end = entries + count;
        if (static_cast<int>(count - 1) >= 0) {
            do {
                --end;
                end->FUN_002c3ac0();
            } while (--count);
        }
        FUN_0008d340(header);
    }
    FUN_0008d340(allocation);
    FUN_0027afd0();
}
}
