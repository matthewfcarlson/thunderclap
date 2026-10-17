// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CWorldStreamManager,bool,float,float,float>::vfunc_2 @ 0x00205ce0
struct CWorldStreamManager;
typedef bool (__fastcall *StreamCallback)(CWorldStreamManager *, unsigned, float, float, float);
struct Closure3 {
    char padding[0x1c];
    StreamCallback callback;
    CWorldStreamManager *object;
    void vfunc_2(void *unused, float *arguments, bool *result);
};
void Closure3::vfunc_2(void *unused, float *arguments, bool *result)
{
    bool value = callback(object, 0, arguments[0], arguments[1], arguments[2]);
    if (result) *result = value;
}