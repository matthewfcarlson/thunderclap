typedef int(__cdecl* CompareFn)(const void*, const void*);
extern "C" void* __cdecl bsearch(const void*, const void*, unsigned int, unsigned int, CompareFn);
extern "C" int __cdecl Compare(const void*, const void*);
class Container {
  public:
    char pad[0x18];
    int count;
    int* items;
    int Find(int key);
};
int Container::Find(int key) {
    int* base = items;
    int* end = base + count;
    int* p = (int*)bsearch(&key, base, (unsigned int)(end - base), 4, Compare);
    if (p)
        return (int)(p - items);
    return -1;
}
