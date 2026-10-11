class Elem {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(void*);
    virtual int v4(Elem* a, int b, int c);
};
class Arg {
  public:
    void* Get();
};
struct Container {
    int m_a;
    int m_b;
    int m_count;
    Elem* arr[1];
    int Find(Elem* arg, int p2, int p3);
};
int Container::Find(Elem* arg, int p2, int p3) {
    int i = 0;
    Elem** p = arr;
    if (m_count > 0) {
        do {
            if (arr[i]->v3(((Arg*)arg)->Get()) == 1)
                return arr[i]->v4(arg, p2, p3);
            i++;
        } while (i < m_count);
    }
    return 0;
}
