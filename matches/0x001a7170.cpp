void* operator new(unsigned int) throw();
class Base {
  public:
    Base(const char*) throw();
    virtual void v0();
    char pad[0xc];
};
class EnumList : public Base {
  public:
    EnumList(const char*) throw();
    virtual void v0();
    const void* tbl;
    int count;
    void* fn;
    int pad2;
};
extern char gTable[];
extern char gFunc[];
extern void __cdecl Register(void*, void**, int) throw();
extern char gList[];
extern int gRef;
EnumList::EnumList(const char* n) throw() : Base(n) {
    tbl = gTable;
    count = 8;
    fn = gFunc;
}
void target() {
    if (!gRef) {
        EnumList* p = new EnumList("stateDesc");
        Register(gList, (void**)&p, 1);
    }
    ++gRef;
}
