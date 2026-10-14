class Elem_2aa590 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(void*);
    virtual int v4(Elem_2aa590* a, int b);
};
class Arg_2aa590 {
  public:
    void* Get();
};
struct Container_2aa590 {
    int m_a;
    int m_b;
    unsigned m_count;
    Elem_2aa590* arr[1];
    int Find(Elem_2aa590* arg, int p2);
};
int Container_2aa590::Find(Elem_2aa590* arg, int p2) {
    unsigned i = 0;
    Elem_2aa590** p = arr;
    if (m_count > 0) {
        do {
            if (arr[i]->v3(((Arg_2aa590*)arg)->Get()) == 1)
                return arr[i]->v4(arg, p2);
            i++;
        } while (i < m_count);
    }
    return 0;
}
