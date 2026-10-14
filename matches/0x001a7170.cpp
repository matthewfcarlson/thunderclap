void* operator new(unsigned int) throw();
class Base_1a7170 {
  public:
    Base_1a7170(const char*) throw();
    virtual void v0();
    char pad[0xc];
};
class EnumList : public Base_1a7170 {
  public:
    EnumList(const char*) throw();
    virtual void v0();
    const void* tbl;
    int count;
    void* fn;
    int pad2;
};
extern char gTable_1a7170[];
extern char gFunc[];
extern void __cdecl Register(void*, void**, int) throw();
extern char gList_1a7170[];
extern int gRef;
EnumList::EnumList(const char* n) throw() : Base_1a7170(n) {
    tbl = gTable_1a7170;
    count = 8;
    fn = gFunc;
}
void target() {
    if (!gRef) {
        EnumList* p = new EnumList("stateDesc");
        Register(gList_1a7170, (void**)&p, 1);
    }
    ++gRef;
}
