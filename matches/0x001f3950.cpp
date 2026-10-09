extern float gScale;
void __cdecl Apply(int, float);
class Obj { public: char pad0[0xc0]; int mPtr; char pad1[0x268]; int mBusy; void Set(float value); };
void Obj::Set(float value) {
    *(volatile float*)0x4c7df0 = value;
    if (mPtr != 0 && mBusy == 0) {
        int x = *(int *)(mPtr + 4);
        if (x != 0) Apply(x, value * 0.01f);
    }
}