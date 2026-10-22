void* operator new(unsigned int) throw();
class ParamValueEnum_1a7170 {
  public:
    ParamValueEnum_1a7170(const char*) throw();
    virtual void v0();
    char pad[0xc];
};
class ParamEnumConstList_1a7170 : public ParamValueEnum_1a7170 {
  public:
    ParamEnumConstList_1a7170(const char*) throw();
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
ParamEnumConstList_1a7170::ParamEnumConstList_1a7170(const char* n) throw() : ParamValueEnum_1a7170(n) {
    tbl = gTable_1a7170;
    count = 8;
    fn = gFunc;
}
void target() {
    if (!gRef) {
        ParamEnumConstList_1a7170* p = new ParamEnumConstList_1a7170("stateDesc");
        Register(gList_1a7170, (void**)&p, 1);
    }
    ++gRef;
}
