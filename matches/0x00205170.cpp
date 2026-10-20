struct CWorldStreamManager {
    bool FUN_00205170(float, float, float);
};
struct Method3 {
    char pad[0x1c];
    bool (CWorldStreamManager::*callback)(float, float, float);
    void vfunc_2(CWorldStreamManager* object, const float* args, bool* result);
};
void Method3::vfunc_2(CWorldStreamManager* object, const float* args, bool* result) {
    bool (CWorldStreamManager::*fn)(float, float, float) = callback;
    float a = args[0], b = args[1], c = args[2];
    bool value = (object->*fn)(a, b, c);
    if (result)
        *result = value;
}