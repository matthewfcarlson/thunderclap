struct Obj {
    void* a;
    int b, c, d;
};
struct Stream {
    bool Open(Obj*, const char*);
    void Close();
};
struct Manager {
    void Add(void*, int);
};
struct Owner {
    char pad[4];
    Stream* stream;
    void Fn();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern Manager* gManager;
extern const char filename[];
extern char MyFileStream_vftable[];
extern char DataHandlerRawLoader_vftable[];
void Owner::Fn() {
    Obj local;
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
    gManager->Add(p, 0x60000a00);
}
