struct Obj_1a5700 {
    void M1(void*);
    void M2();
    void M3();
};
struct Other_1a5700 {
    void Call();
};
struct Item_1a5700 {
    char pad[0x34];
    void Run(void* arg);
};
void Item_1a5700::Run(void* arg) {
    unsigned char* p = (unsigned char*)this + 0x34;
    for (int i = 0; i < 20; i++, p += 0x18) {
        if (*(p - 8) && *(Obj_1a5700**)p) {
            (*(Obj_1a5700**)p)->M1(arg);
            (*(Obj_1a5700**)p)->M2();
            Other_1a5700* o = *(Other_1a5700**)(p + 4);
            if (o)
                o->Call();
            (*(Obj_1a5700**)p)->M3();
        }
    }
}
