struct Elem_30e250 {
    void process();
};
class CollisionAnalyser {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, int);
    virtual void vfunc_3();
    virtual void vfunc_4();
    unsigned char* begin;
    unsigned char* end;
    char pad[4];
    unsigned char flag;
    void init();
};
void CollisionAnalyser::vfunc_2(int, int) {
    init();
    unsigned char* p = begin;
    flag = 0;
    if (p <= end) {
        do {
            ((Elem_30e250*)*(void**)(p + 0x10))->process();
            unsigned char* old = p;
            p += 0x14;
            if (old == end)
                break;
        } while (1);
    }
}