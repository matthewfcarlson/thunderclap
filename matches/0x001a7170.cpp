#include "decls/data/game/hulkfight/scenario.h"
// data: gList_1a7170 = DAT_004e1730, gTable_1a7170 = DAT_004c165c

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
extern char gFunc[];
extern void __cdecl Register(void*, void**, int) throw();
ParamEnumConstList_1a7170::ParamEnumConstList_1a7170(const char* n) throw() : ParamValueEnum_1a7170(n) {
    tbl = ((char*)&DAT_004c165c);
    count = 8;
    fn = gFunc;
}
void target() {
    if (!(*(int*)&DAT_004e1734)) {
        ParamEnumConstList_1a7170* p = new ParamEnumConstList_1a7170("stateDesc");
        Register(((char*)&DAT_004e1730), (void**)&p, 1);
    }
    ++(*(int*)&DAT_004e1734);
}
