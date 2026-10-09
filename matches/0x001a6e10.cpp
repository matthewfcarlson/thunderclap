class Owner { public: void* Get(); void* Find(); };
extern int Check(void*, int, void*, void*, int);
void* Owner::Find() {
    void* p = Get();
    while (p != 0 && Check(p, 0, (void*)0x48d5bc, (void*)0x4a15cc, 0) == 0) {
        p = Get();
    }
    return p;
}