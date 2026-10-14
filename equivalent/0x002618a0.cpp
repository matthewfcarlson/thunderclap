// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002618a0 @ 0x002618a0
extern "C" double fmod(double x, double y);

struct Node {
    char pad0;
};
extern "C" Node* __cdecl FUN_002611b0(void* owner);
extern "C" float __cdecl FUN_00260d00(void* node);
extern "C" void __cdecl FUN_00260be0(void* owner, float value);

void FUN_002618a0(void* owner) {
    float result = FUN_00260d00(FUN_002611b0(owner));
    char* node = (char*)FUN_002611b0(owner);
    while (*node) {
        float factor = FUN_00260d00(node);
        if (factor != 0.0f)
            result = (float)fmod(result, factor);
        node = (char*)FUN_002611b0(owner);
    }
    FUN_00260be0(owner, result);
}
