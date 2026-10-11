// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00240a10 @ 0x00240a10
class Singleton {
public:
    virtual void v0();
    virtual void v1();
};

struct Handle {
    char pad0[0x68];
    int id;                  // 0x68
};

struct Pool {
    void FUN_002659a0(int id);
};

struct Resource {
    void FUN_00240060();
};

extern unsigned char DAT_004e5ca4;
extern Resource *DAT_004e5ca0;
extern char DAT_004e5cac;
extern Pool *DAT_00527c58;

void __cdecl FUN_00242c10(char *guard);
Handle *__cdecl FUN_00245330();
Handle *__cdecl FUN_00256660();
Handle *__cdecl FUN_00241660();
Handle *__cdecl FUN_0024d5a0();
void __cdecl FUN_0024d630();
void __cdecl FUN_0008d330(void *p);

Singleton *__cdecl FUN_00255d20();
Singleton *__cdecl FUN_00255480();
Singleton *__cdecl FUN_00254e70();
Singleton *__cdecl FUN_00254a70();
Singleton *__cdecl FUN_00254640();
Singleton *__cdecl FUN_00253c50();
Singleton *__cdecl FUN_00253770();
Singleton *__cdecl FUN_00253390();
Singleton *__cdecl FUN_00252fb0();
Singleton *__cdecl FUN_00252b50();
Singleton *__cdecl FUN_002527a0();
Singleton *__cdecl FUN_00252370();
Singleton *__cdecl FUN_002518d0();
Singleton *__cdecl FUN_002513c0();
Singleton *__cdecl FUN_00250db0();
Singleton *__cdecl FUN_002509b0();
Singleton *__cdecl FUN_00250540();
Singleton *__cdecl FUN_002500d0();
Singleton *__cdecl FUN_0024fc50();
Singleton *__cdecl FUN_0024f810();
Singleton *__cdecl FUN_0024ea00();
Singleton *__cdecl FUN_0024e540();

void FUN_00240a10()
{
    FUN_00242c10(&DAT_004e5cac);
    if (DAT_004e5ca4 & 1) {
        DAT_00527c58->FUN_002659a0(FUN_00245330()->id);
        DAT_00527c58->FUN_002659a0(FUN_00256660()->id);
        DAT_00527c58->FUN_002659a0(FUN_00241660()->id);
        DAT_00527c58->FUN_002659a0(FUN_0024d5a0()->id);
    }
    FUN_0024d630();
    FUN_00255d20()->v1();
    FUN_00255480()->v1();
    FUN_00254e70()->v1();
    FUN_00254a70()->v1();
    FUN_00254640()->v1();
    FUN_00253c50()->v1();
    FUN_00253770()->v1();
    FUN_00253390()->v1();
    FUN_00252fb0()->v1();
    FUN_00252b50()->v1();
    FUN_002527a0()->v1();
    FUN_00252370()->v1();
    FUN_002518d0()->v1();
    FUN_002513c0()->v1();
    FUN_00250db0()->v1();
    FUN_002509b0()->v1();
    FUN_00250540()->v1();
    FUN_002500d0()->v1();
    FUN_0024fc50()->v1();
    FUN_0024f810()->v1();
    FUN_0024ea00()->v1();
    FUN_0024e540()->v1();
    Resource *res = DAT_004e5ca0;
    if (res) {
        res->FUN_00240060();
        FUN_0008d330(res);
    }
    DAT_004e5ca0 = 0;
}
