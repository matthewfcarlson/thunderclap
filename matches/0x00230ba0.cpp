typedef int(__cdecl* CompareFn_230ba0)(void*, void*);
class List_230ba0 {
  public:
    void* head;
    void* Find(CompareFn_230ba0 fn, void* key);
};
void* List_230ba0::Find(CompareFn_230ba0 fn, void* key) {
    void* p = head;
    void* end = (char*)this + 4;
    while (p != end) {
        int r = fn(key, p);
        if (r < 0)
            p = *(void**)p;
        else if (r > 0)
            p = *((void**)p + 1);
        else
            return p;
    }
    return 0;
}