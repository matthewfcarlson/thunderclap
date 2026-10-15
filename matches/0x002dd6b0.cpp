typedef unsigned int size_t;
struct File {
    char pad[0x5c];
    void* handle;
};
extern "C" size_t __cdecl fread(void*, size_t, size_t, void*);
extern "C" void __cdecl report(File*, const char*);
void __cdecl readFile(File* file, void* dest, unsigned int count) {
    if (fread(dest, 1, count, file->handle) != count)
        report(file, "Read Error");
}