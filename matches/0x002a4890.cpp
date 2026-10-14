class Item_2a4890 {
  public:
    virtual void f0();
    virtual void Release();
};
extern void Free(void*);
class Container_2a4890 {
  public:
    Item_2a4890* first;
    Item_2a4890** begin;
    Item_2a4890** end;
    void Clear();
};
void Container_2a4890::Clear() {
    if (first) {
        first->Release();
        first = 0;
    }
    unsigned int n = (unsigned int)(((char*)end - (char*)begin) >> 2);
    unsigned int i = 0;
    if (n <= 0) {
    } else
        do {
            Item_2a4890** q = begin + i;
            if (*q) {
                (*q)->Release();
                *q = 0;
            }
            ++i;
        } while (i < n);
    if (begin)
        Free(begin);
}