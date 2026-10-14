// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002088a0 @ 0x002088a0
class Releasable {
public:
    virtual void v0();
    virtual void Release();
};

struct Buffer {
    void FUN_00263e90();
};

struct Slot {
    unsigned char active;       // +0x00
    unsigned char ready;        // +0x01
    char pad02[0x20];
    short handle;               // +0x22
    char pad24[4];
    char *name;                 // +0x28
    Releasable *resource;       // +0x2c
    char pad30[4];
    Buffer *buffer;             // +0x34
    char pad38[4];
};

extern char DAT_004c91d8;

void __cdecl FUN_00267090(char *p);
void __cdecl FUN_00267110(int handle);

class Pool {
public:
    void FUN_002088a0();
    void FUN_00207e80();

    char pad0[0x4c];
    Slot slots[20];             // +0x4c
    char pad4fc[0xaf4 - 0x4fc];
    char cleared;               // +0xaf4
};

void Pool::FUN_002088a0() {
    FUN_00207e80();
    if (DAT_004c91d8 != 0) {
        for (int i = 0; i < 20; i++) {
            Slot *s = &slots[i];
            if (s->buffer != 0) {
                s->buffer->FUN_00263e90();
                s->buffer = 0;
            }
            if (s->resource != 0) {
                FUN_00267110(s->handle);
            }
            if (s->resource != 0) {
                s->resource->Release();
                s->resource = 0;
            }
            if (s->name != 0) {
                FUN_00267090(s->name);
                s->name = 0;
            }
            s->active = 0;
            s->ready = 0;
            s->handle = 0;
        }
    }
    cleared = 1;
}
