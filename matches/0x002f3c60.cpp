void Free(void* p);
void Free2(void* p);
struct T {
    char d[0x18];
    void Dtor();
    T* Del(unsigned char f);
};
T* T::Del(unsigned char f) {
    if (f & 2) {
        int n = ((int*)this)[-1];
        T* p = this + n;
        while (--n >= 0) {
            --p;
            p->Dtor();
        }
        if (f & 1)
            Free((int*)this - 1);
        return (T*)((int*)this - 1);
    }
    Dtor();
    if (f & 1)
        Free2(this);
    return this;
}
