void* __cdecl operator new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* where) { return where; }

struct InitHelper {
    void init();
};

struct TrackImpl {
    int m0;
    int m1;
    void setup(void* arg);
};

class TrackFactoryTemplate {
public:
    TrackFactoryTemplate() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};

void postInit();

class TrackFactoryCasterTemplate {
public:
    virtual void cast0();
    virtual void* vfunc_1(void* arg);
};

void* TrackFactoryCasterTemplate::vfunc_1(void* arg) {
    void* mem = operator new(0x10);
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate* t = new (mem) TrackFactoryTemplate();
        t->mTrack.setup(arg);
        postInit();
        return t;
    }
    return 0;
}
