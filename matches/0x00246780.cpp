extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, void*);
struct File {
    char pad[0x1c];
    void* handle;
};
bool __cdecl Read(File* f, void* p, unsigned int n) {
    return fread(p, n, 1, f->handle) == 1;
}