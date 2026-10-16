#include "gen/global.h"

struct File_1fada0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Read(void* buf, int len, int one);
    virtual void v4();
    virtual void v5();
    virtual void GetPos(int* out);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void Sync();
};

int MyFileStream::vfunc_3(void* __p0, int len) { void * buf = (void *)__p0;

    int n = this->f_0c - this->f_08;
    if (n < len)
        len = n;
    int p0;
    (*(File_1fada0 * *)&this->f_04)->GetPos(&p0);
    (*(File_1fada0 * *)&this->f_04)->Sync();
    (*(File_1fada0 * *)&this->f_04)->Read(buf, len, 1);
    (*(File_1fada0 * *)&this->f_04)->Sync();
    int p1;
    (*(File_1fada0 * *)&this->f_04)->GetPos(&p1);
    (*(File_1fada0 * *)&this->f_04)->Sync();
    this->f_08 += p1 - p0;
    return p1 - p0;
}
