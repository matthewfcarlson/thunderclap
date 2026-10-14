extern unsigned int GetSize();
extern unsigned int* Allocate(unsigned int);

struct Owner_24f180 {
    char pad[0x40];
    unsigned int* data;
};

unsigned int* __fastcall FUN_0024f180(Owner_24f180* self) {
    unsigned int* p = Allocate(GetSize());
    unsigned int* r;
    if (p) {
        for (int i = 0; i != 0x40; ++i)
            p[i] = 0x3f800000;
        r = p;
    } else {
        r = 0;
    }
    self->data = r;
    return r;
}
