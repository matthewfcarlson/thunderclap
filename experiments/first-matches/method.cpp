// Matching experiment (names/layouts are guesses). Verify with:
//   build/venv/bin/python tools/compare.py <this file> <symbol> <address>

class MethodBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void Invoke(void* object, void* args, void* result) = 0;
    char pad[0x18];
};

template <class T, class R>
class Method0 : public MethodBase {
public:
    typedef R (T::*Fn)();
    // FUNCTION: 0x0002cf30 (Method0<CActorManager,int>::vfunc_2)
    virtual void Invoke(void* object, void* args, void* result) {
        Fn fn = mFn;
        R r = (static_cast<T*>(object)->*fn)();
        if (result) *static_cast<R*>(result) = r;
    }
    Fn mFn;
};

template <class T, class R, class A1>
class Method1 : public MethodBase {
public:
    typedef R (T::*Fn)(A1);
    virtual void Invoke(void* object, void* args, void* result);
    Fn mFn;
};

template <class T, class A1>
class Method1<T, void, A1> : public MethodBase {
public:
    typedef void (T::*Fn)(A1);
    // FUNCTION: 0x0002ce30 (Method1<CActorManager,void,const char*>::vfunc_2)
    virtual void Invoke(void* object, void* args, void* result) {
        (static_cast<T*>(object)->*mFn)(*static_cast<A1*>(args));
    }
    Fn mFn;
};

class CActorManager {
public:
    int GetCount();
    void Spawn(const char* name);
};

template class Method0<CActorManager, int>;
template class Method1<CActorManager, void, const char*>;
