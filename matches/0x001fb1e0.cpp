struct Obj_1fb1e0 {
    void* a;
    int b, c, d;
};
struct Stream {
    bool Open(Obj_1fb1e0*, const char*);
    void Close();
};
struct Manager_1fb1e0 {
    void Add(void*, int);
};
struct Owner_1fb1e0 {
    char pad[4];
    Stream* stream;
    void Fn();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern Manager_1fb1e0* gManager_1fb1e0;
extern const char filename[];
extern char MyFileStream_vftable[];
extern char DataHandlerRawLoader_vftable[];
void Owner_1fb1e0::Fn() {
    Obj_1fb1e0 local;
    local.a = MyFileStream_vftable;
    local.b = 0;
    local.c = 0;
    local.d = 0;
    if (!stream->Open(&local, "scripts/all_defs.dhd"))
        stream->Close();
    char* p = (char*)Alloc(0x18);
    if (p) {
        *(int*)(p + 4) = 0;
        *(int*)(p + 8) = 0x60000a00;
        *(int*)(p + 12) = 0;
        *(int*)(p + 16) = 0;
        *(void**)p = DataHandlerRawLoader_vftable;
        *(void**)(p + 20) = this;
    } else
        p = 0;
    gManager_1fb1e0->Add(p, 0x60000a00);
}
