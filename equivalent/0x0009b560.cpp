// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0009b560 @ 0x0009b560
class Target_9b560 {
public:
    char Dummy(int a0, int a1, int a2, int a3, int a4, int a5);
};
typedef char (Target_9b560::*Callback_9b560)(int a0, int a1, int a2, int a3, int a4, int a5);
union CallbackBits {
    unsigned int raw;
    Callback_9b560 fn;
};
void __cdecl FUN_0009b560(Target_9b560* obj, int* args, char* result, unsigned int fnAddr) {
    CallbackBits cb;
    cb.raw = fnAddr;
    char r = (obj->*(cb.fn))(args[0], args[1], args[2], args[3], args[4], args[5]);
    if (result)
        *result = r;
}
