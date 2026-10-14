// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_00286520 @ 0x00286520
inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int size);

namespace pure3d {

class Handler {
public:
    virtual void AddRef();
    virtual void Release();
    int f4;
};

class DefaultFrameControllerHandler : public Handler {
public:
    DefaultFrameControllerHandler() { f4 = 0; }
    virtual void AddRef();
    virtual void Release();
};

class FrameControllerLoader {
public:
    FrameControllerLoader();
    virtual void l0();
    int f4;
    int id;
    int fc;
    int f10;
    unsigned int handlerCount;
    Handler* handlers[4];
};

FrameControllerLoader::FrameControllerLoader() {
    f4 = 0;
    id = 0x121201;
    fc = 0;
    f10 = 0;
    handlerCount = 0;
    handlers[0] = 0;
    handlers[1] = 0;
    handlers[2] = 0;
    handlers[3] = 0;
    void* mem = FUN_0008d690(8);
    if (mem) {
        DefaultFrameControllerHandler* h = new (mem) DefaultFrameControllerHandler();
        unsigned int n = handlerCount;
        if (n < 4) {
            h->AddRef();
            if (handlers[n])
                handlers[n]->Release();
            handlers[n] = h;
            handlerCount++;
        }
    }
}

}
