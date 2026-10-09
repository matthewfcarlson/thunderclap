typedef int (__cdecl *CompareFn)(void*, void*);
class List {
public:
    void* head;
    void* Find(CompareFn fn, void* key);
};
void* List::Find(CompareFn fn, void* key) {
    void* p = head;
    void* end = (char*)this + 4;
    while (p != end) {
        int r = fn(key, p);
        if (r < 0) p = *(void**)p;
        else if (r > 0) p = *((void**)p + 1);
        else return p;
    }
    return 0;
}