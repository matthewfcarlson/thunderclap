struct Resource_2d6590 {
    virtual void slot0();
    virtual void release();
};
struct Pool_2d6590 {
    char pad[8];
    unsigned count;
    void** items;
};
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
namespace pure3d {
struct SpriteParticleEmitter {
    virtual void slot0();
    char pad04[0x80];
    Pool_2d6590* pool;
    char pad88[0xc];
    unsigned resourceCount;
    char pad98[0x10];
    Resource_2d6590* resourceA8;
    char padAC[0x94];
    void* buffer;
    char pad144[8];
    unsigned itemCount;
    char pad150[0x6c];
    Resource_2d6590* resource1BC;
    Resource_2d6590* resource1C0;
    Resource_2d6590* resource1C4;
    void** items;
    char pad1CC[8];
    Resource_2d6590** resources;
    void FUN_002d4b50();
    ~SpriteParticleEmitter();
};
SpriteParticleEmitter::~SpriteParticleEmitter() {
    Pool_2d6590* p = pool;
    for (unsigned i = 0; i < itemCount; ++i) {
        void** entry = &items[i];
        if (*entry) {
            p->items[p->count] = *entry;
            ++p->count;
            *entry = 0;
        }
    }
    if (resource1BC) {
        resource1BC->release();
        resource1BC = 0;
    }
    for (unsigned i = 0; i < resourceCount; ++i) {
        Resource_2d6590** entry = &resources[i];
        if (*entry) {
            (*entry)->release();
            *entry = 0;
        }
    }
    if (resource1C0) {
        resource1C0->release();
        resource1C0 = 0;
    }
    if (resource1C4) {
        resource1C4->release();
        resource1C4 = 0;
    }
    if (resources)
        FUN_0008d340(resources);
    if (items)
        FUN_0008d340(items);
    if (resourceA8) {
        resourceA8->release();
        resourceA8 = 0;
    }
    FUN_0008d330(buffer);
    FUN_002d4b50();
}
} // namespace pure3d
