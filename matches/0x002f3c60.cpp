void Free(void* p);
void Free2(void* p);
struct T_2f3c60 {
    char d[0x18];
    void Dtor();
    T_2f3c60* Del(unsigned char f);
};
T_2f3c60* T_2f3c60::Del(unsigned char f) {
    if (f & 2) {
        int n = ((int*)this)[-1];
        T_2f3c60* p = this + n;
        while (--n >= 0) {
            --p;
            p->Dtor();
        }
        if (f & 1)
            Free((int*)this - 1);
        return (T_2f3c60*)((int*)this - 1);
    }
    Dtor();
    if (f & 1)
        Free2(this);
    return this;
}
