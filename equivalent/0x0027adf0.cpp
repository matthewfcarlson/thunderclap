// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// RDLReader::vfunc_0 @ 0x0027adf0
#include "gen/global.h"

struct Stream_27adf0 {
    virtual void s0();
    virtual void release();
    virtual void s2();
    virtual void read(char *buf, int size, int count);
    virtual void s4(); virtual void s5(); virtual void s6();
    virtual void readSize(int *out);
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14();
    virtual int size();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void reset();
    virtual void s22();
    virtual bool valid();
};
extern "C" void __cdecl thunk_FUN_002710d0(Stream_27adf0 **, const char *, int, int, int, int, int, int);
char *__cdecl FUN_0008d690(int size);

void RDLReader::vfunc_0(int __p0) { const char * path = (const char *)__p0;

    vfunc_1();
    thunk_FUN_002710d0(&(*(Stream_27adf0 * *)&this->f_04), path, 0, 0, 1, 0, 1, 1);
    (*(Stream_27adf0 * *)&this->f_04)->reset();
    if (!(*(Stream_27adf0 * *)&this->f_04)->valid() || (*(Stream_27adf0 * *)&this->f_04)->size() == 0) {
        (*(Stream_27adf0 * *)&this->f_04)->release();
        (*(Stream_27adf0 * *)&this->f_04) = 0;
        return;
    }
    (*(Stream_27adf0 * *)&this->f_04)->readSize(&this->f_10);
    (*(Stream_27adf0 * *)&this->f_04)->reset();
    (*(char * *)&this->f_08) = FUN_0008d690(this->f_10);
    (*(Stream_27adf0 * *)&this->f_04)->read((*(char * *)&this->f_08), this->f_10, 1);
    (*(Stream_27adf0 * *)&this->f_04)->reset();
    this->f_0c = 0;
}
