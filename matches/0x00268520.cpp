extern "C" void __stdcall XInputClose(void*);
struct ControllerXBox {
    char p0[8];
    void* handle;
    char p[0x41c];
    void Shutdown();
};
void ControllerXBox::Shutdown() {
    *(unsigned long*)this = 0x42b14c;
    if (handle)
        XInputClose(handle);
    unsigned long* q = (unsigned long*)((char*)this + 0x448);
    int n = 2;
    do {
        q -= 4;
        n--;
        *q = 0x3f6098;
    } while (n);
    q = (unsigned long*)((char*)this + 0x428);
    n = 0x14;
    do {
        q -= 0xd;
        n--;
        *q = 0x3f6098;
    } while (n);
    *(unsigned long*)this = 0x3f6098;
}
