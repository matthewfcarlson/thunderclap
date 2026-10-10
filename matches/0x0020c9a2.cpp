// cl-flags: /O1
typedef int(__stdcall* LoadFn)(int);
extern LoadFn gLoad;
namespace XAPILIB {
void __stdcall XapiSetLastNTError(int);
}
struct Obj {
    int x;
    int value;
};
int __stdcall target(Obj* p) {
    int r = gLoad((int)p);
    int result;
    if ((r < 0)) {
        XAPILIB::XapiSetLastNTError(r);
        result = 0;
    } else {
        result = p->value;
    }
    return result;
}
