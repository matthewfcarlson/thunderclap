// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 62/62)
// FUN_00291dc0 @ 0x00291dc0
#include "decls/data/engine/content.h"

extern "C" void* __cdecl FUN_00263ea0(unsigned int size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

class __declspec(novtable) LoaderBase_291dc0 {
  public:
    virtual void slot0();
    int f04;
    int id;
    int f0c;
    int f10;
};

class __declspec(novtable) FileLoaderBase {
  public:
    virtual void slot0();
    int f04;
    int f08;
};

class __declspec(novtable) ImageHandlerBase {
  public:
    virtual void slot0();
    char pad[0x14];
    void FUN_002af0c0();
    ImageHandlerBase() { FUN_002af0c0(); }
};

namespace content {
class P3DFileHandler : public FileLoaderBase {
  public:
    P3DFileHandler() { f04 = 0; f08 = 0; }
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
}

namespace pure3d {
class PNGHandler : public ImageHandlerBase {
  public:
    PNGHandler() {}
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
};
class BMPHandler : public ImageHandlerBase {
  public:
    BMPHandler() {}
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
};
class IgnoreLoader : public LoaderBase_291dc0 {
  public:
    IgnoreLoader() { f04 = 0; id = 0; f0c = 0; f10 = 0; }
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
};
}

struct Raw_291dc0 {
    LoaderBase_291dc0* FUN_002c29b0();
    LoaderBase_291dc0* FUN_002c25b0();
    LoaderBase_291dc0* FUN_0028f280();
    LoaderBase_291dc0* FUN_002c1b30();
    LoaderBase_291dc0* FUN_002c1480();
    LoaderBase_291dc0* FUN_002c1930();
    LoaderBase_291dc0* FUN_002c14c0();
    LoaderBase_291dc0* FUN_002c0c40();
    LoaderBase_291dc0* FUN_002955c0();
    LoaderBase_291dc0* FUN_002bfa30();
    LoaderBase_291dc0* FUN_002beca0();
    LoaderBase_291dc0* FUN_002bc3d0();
    LoaderBase_291dc0* FUN_0027b980();
    LoaderBase_291dc0* FUN_002b7d30();
    LoaderBase_291dc0* FUN_00299410();
    LoaderBase_291dc0* FUN_002b6150();
    LoaderBase_291dc0* FUN_002b6870();
    LoaderBase_291dc0* FUN_002b68c0();
    LoaderBase_291dc0* FUN_00289e00();
    LoaderBase_291dc0* FUN_00286520();
    LoaderBase_291dc0* FUN_002b23a0();
    LoaderBase_291dc0* FUN_002acc60();
    LoaderBase_291dc0* FUN_00297150();
    LoaderBase_291dc0* FUN_002aff60();
    LoaderBase_291dc0* FUN_002b0f40();
    LoaderBase_291dc0* FUN_002aff20();
    LoaderBase_291dc0* FUN_00290740();
};

struct Registry_291dc0 {
    void FUN_00265210(void*, int);
    void FUN_00265240(void*, const char*);
};

void FUN_00291dc0(){
    void* mem = FUN_00263ea0(0xc);
    content::P3DFileHandler* p3d = 0;
    if (mem) p3d = new (mem) content::P3DFileHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(p3d, "p3d");
    mem = FUN_00263ea0(0x18);
    pure3d::PNGHandler* png = 0;
    if (mem) png = new (mem) pure3d::PNGHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(png, "png");
    mem = FUN_00263ea0(0x18);
    pure3d::BMPHandler* bmp = 0;
    if (mem) bmp = new (mem) pure3d::BMPHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(bmp, "bmp");
    LoaderBase_291dc0* l;
    mem = FUN_00263ea0(0x2c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c29b0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10000);
    mem = FUN_00263ea0(0x1c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c25b0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_0028f280() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x11000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1b30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x2200);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1480() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x13000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1930() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x14000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c14c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x2380);
    mem = FUN_00263ea0(0x1c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c0c40() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19001);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002955c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x22000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002bfa30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x22002);
    mem = FUN_00263ea0(0x24);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002beca0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19005);
    mem = FUN_00263ea0(0x18);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002bc3d0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x17006);
    mem = FUN_00263ea0(0x18);
    l = mem ? ((Raw_291dc0*)mem)->FUN_0027b980() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x23000);
    mem = FUN_00263ea0(0x2c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b7d30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10001);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00299410() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x123000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b6150() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x1001a);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b6870() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10019);
    mem = FUN_00263ea0(0x18);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b68c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10023);
    mem = FUN_00263ea0(0x24);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00289e00() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121000);
    mem = FUN_00263ea0(0x28);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00286520() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121201);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b23a0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121202);
    mem = FUN_00263ea0(0x3c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002acc60() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x1580c);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00297150() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x120100);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002aff60() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21001);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b0f40() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21002);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002aff20() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00290740() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x802000a);
    mem = FUN_00263ea0(0x14);
    pure3d::IgnoreLoader* ign = 0;
    if (mem) ign = new (mem) pure3d::IgnoreLoader();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x7000);
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x7001);
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x1001d);
}
