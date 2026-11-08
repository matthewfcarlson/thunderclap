#include "decls/data/records.h"
#include "gen/core.h"
// the file's drive: slot 10 closes a handle (core::XboxDrive 0x0026f1d0)
struct Sink_273da0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Do(int a, char* b);
};
struct Sub_273da0 {
    virtual void Fin();
    virtual void Rel();
};
// the file's cement library view (records.h CoreFileView): 0x00277ca0 has one, 0x00277ce0 releases it
struct View_273da0 {
    bool FUN_00277ca0();
    void FUN_00277ce0();
};
// core::FileCloseRequest::vfunc_1 (records.h CoreFile): closes the drive's handle (the view's word 11) or the view,
// then the file is closed (flag1c) and its error cleared (field14, under its IMutable lock)
int core::FileCloseRequest::vfunc_1() {
    Sink_273da0* s = (Sink_273da0*)((CoreFile*)this->f_08)->provider;
    if (!((View_273da0*)&((CoreFile*)this->f_08)->view)->FUN_00277ca0())
        s->Do((int)((CoreFile*)this->f_08)->view.words[11], ((CoreFile*)this->f_08)->filename);
    else
        ((View_273da0*)&((CoreFile*)this->f_08)->view)->FUN_00277ce0();
    ((CoreFile*)this->f_08)->flag1c = 0;
    ((Sub_273da0*)&((CoreFile*)this->f_08)->vftableMutable)->Fin();
    ((CoreFile*)this->f_08)->field14 = 0;
    ((Sub_273da0*)&((CoreFile*)this->f_08)->vftableMutable)->Rel();
    return 1;
}
