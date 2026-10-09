typedef unsigned char u8;
class Obj { public: char pad[0x3c]; int m3c; int m40; Obj* Update(u8); };
extern void Copy(void*, int);
extern void InitA(void*);
extern void InitB(void*);
Obj* Obj::Update(u8 flag) {
    Copy((void*)0x4e6158, m40);
    Copy((void*)0x4e6110, m3c);
    char* base = (char*)this + 0x50;
    InitA(base + 0x14);
    InitB(base);
    if (flag & 1) Copy((void*)0x4e60c8, (int)this);
    return this;
}