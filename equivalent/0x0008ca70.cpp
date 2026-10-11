// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 21/22, incomplete)
// FUN_0008ca70 @ 0x0008ca70
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct CreateParams {
    void* buffer;
    int a;
    int b;
    int c;
    int d;
    int e;
};

class Obj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(int a, int b, int c);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual int v58();
    virtual int v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90(Obj** out, CreateParams p);
};

struct Slot {
    Obj* obj;
    Obj* aux;
    char pad08[0xc0];
};

extern "C" int FUN_0026b800(int a, int b, char* buf, int c, int d, int e, int f);

class Manager {
public:
    char pad00[8];
    Slot* slots;
    int FUN_0008c590(int index, int a, int* status);
    int FUN_0008ca70(int index, int arg1, int arg2, int arg3, int arg4);
};

int Manager::FUN_0008ca70(int index, int arg1, int arg2, int arg3, int arg4)
{
    struct {
        Obj* created;
        int status;
        char buf[0x104];
        unsigned int guard;
    } f;
    int result;
    f.guard = DAT_004d9968;
    Obj* obj = slots[index].obj;
    obj->v58();
    if (slots[index].aux) {
        slots[index].aux->v54();
        Obj** auxSlot = &slots[index].aux;
        if (*auxSlot) {
            (*auxSlot)->v04();
            *auxSlot = 0;
        }
    }
    result = FUN_0008c590(index, arg1, &f.status);
    if (result == 0) {
        if (f.status == 2) {
            result = 1;
        } else {
            if (arg4 != 0)
                FUN_0026b800(arg4, 2, f.buf, 1, 0x2e, 0x40, 0);
            CreateParams p;
            f.created = 0;
            p.buffer = f.buf;
            p.a = 0;
            p.b = 0;
            p.c = 0;
            p.d = 0;
            p.e = 1;
            obj->v90(&f.created, p);
            result = obj->v5c();
            if (result == 1)
                result = 0xc;
            if (f.created) {
                if (result == 0) {
                    result = f.created->v58();
                    if (result == 0 && (char)f.created->v5c()) {
                        f.created->v24(arg2, arg3, 1);
                        result = f.created->v58();
                    }
                }
                if (f.created)
                    f.created->v04();
            }
        }
    }
    __security_check_cookie(f.guard);
    return result;
}
