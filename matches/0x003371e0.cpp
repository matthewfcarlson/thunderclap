extern "C" char DAT_00434318[];
struct Element {
    char pad[0x18];
    void f();
};
struct Obj {
    char pad[0x288];
    void run();
};
void Obj::run() {
    *(void**)this = (void*)((int)DAT_00434318);
    Element* p = (Element*)((char*)this + 0x288);
    int i = 0x18;
    do {
        p--;
        p->f();
        --i;
    } while (i);
}