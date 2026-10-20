// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_002af2d0 @ 0x002af2d0
#include "decls/data/game/global.h"

inline void *operator new(unsigned int, void *p) throw() { return p; }
void *FUN_0008d690(unsigned int size);
void *FUN_00263ea0(unsigned int size);

class Manager_2af2d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int getA();
    virtual int getB();
};

struct ImageConverter {
    ImageConverter *FUN_002de230();
};

namespace pure3d {

class ImageHandler {
public:
    __forceinline ImageHandler() : f04(0), f08(0), f0c(0) {
        f10 = (*(Manager_2af2d0**)&DAT_0052c2a4)->getB();
        f14 = (*(Manager_2af2d0**)&DAT_0052c2a4)->getA();
    }
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
    int f04;
    int f08;
    char f0c;
    int f10;
    int f14;
};

class PNGHandler : public ImageHandler {
public:
    __forceinline PNGHandler() {}
    virtual void slot0();
};
class BMPHandler : public ImageHandler {
public:
    __forceinline BMPHandler() {}
    virtual void slot0();
};
class TargaHandler : public ImageHandler {
public:
    __forceinline TargaHandler() {}
    virtual void slot0();
};
class RawImageHandler : public ImageHandler {
public:
    __forceinline RawImageHandler() {}
    virtual void slot0();
};
class DXTNHandler : public ImageHandler {
public:
    __forceinline DXTNHandler() {}
    virtual void slot0();
};

}

class ImageRegistry_2af2d0 {
public:
    int count;
    pure3d::ImageHandler *handlers[0x20];
    ImageConverter *converter;
    char flag88;
    char flag89;
    char flag8a;
    char pad8b;
    int f8c;
    int pad90;
    int f94;
    int f98;
    int f9c;
    int fa0;

    ImageRegistry_2af2d0 *FUN_002af2d0();
};

ImageRegistry_2af2d0 *ImageRegistry_2af2d0::FUN_002af2d0()
{
    count = 0;
    flag88 = 0;
    flag89 = 0;
    flag8a = 0;
    f8c = 0x20;
    f94 = 8;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    void *mem = FUN_0008d690(4);
    ImageConverter *conv = 0;
    if (mem)
        conv = ((ImageConverter *)mem)->FUN_002de230();
    converter = conv;

    pure3d::ImageHandler *h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::PNGHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::BMPHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::TargaHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::RawImageHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::DXTNHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;
    return this;
}
