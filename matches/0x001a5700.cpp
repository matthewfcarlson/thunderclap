struct Obj {
    void M1(void*);
    void M2();
    void M3();
};
struct Other {
    void Call();
};
struct Item {
    char pad[0x34];
    void Run(void* arg);
};
void Item::Run(void* arg) {
    unsigned char* p = (unsigned char*)this + 0x34;
    for (int i = 0; i < 20; i++, p += 0x18) {
        if (*(p - 8) && *(Obj**)p) {
            (*(Obj**)p)->M1(arg);
            (*(Obj**)p)->M2();
            Other* o = *(Other**)(p + 4);
            if (o)
                o->Call();
            (*(Obj**)p)->M3();
        }
    }
}
