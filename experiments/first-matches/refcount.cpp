// Matching experiment (names/layouts are guesses). Verify with:
//   build/venv/bin/python tools/compare.py <this file> <symbol> <address>

namespace pure3d {

class NonCopyable {
public:
    virtual void AddRef();
    virtual void Release();
    virtual ~NonCopyable();

    int mRefCount;
};

// FUNCTION: 0x00018b40 (pure3d::NonCopyable::vfunc_1)
void NonCopyable::Release() {
    if (--mRefCount < 1) {
        delete this;
    }
}

}
