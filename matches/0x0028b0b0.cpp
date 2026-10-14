class Elem_28b0b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(void*);
    virtual int v4(Elem_28b0b0* a, int b, int c);
};
class Arg_28b0b0 {
  public:
    void* Get();
};
struct Container_28b0b0 {
    int m_a;
    int m_b;
    int m_count;
    Elem_28b0b0* arr[1];
    int Find(Elem_28b0b0* arg, int p2, int p3);
};
int Container_28b0b0::Find(Elem_28b0b0* arg, int p2, int p3) {
    int i = 0;
    Elem_28b0b0** p = arr;
    if (m_count > 0) {
        do {
            if (arr[i]->v3(((Arg_28b0b0*)arg)->Get()) == 1)
                return arr[i]->v4(arg, p2, p3);
            i++;
        } while (i < m_count);
    }
    return 0;
}
