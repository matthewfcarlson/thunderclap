struct Obj { char pad0[0x40]; int value; char pad1[0xa8]; void* context; };
struct Context { int Get(int); };
extern const float g_one;
extern const float g_hundredth;
extern const float g_factor;
float __fastcall FUN_001d6670(Obj* self) {
    int result = ((Context*)self->context)->Get(self->value);
    bool scale = result == 2;
    float value = 1.0f;
    if (result == 3) value = 0.01f;
    if (scale) value *= 0.025f;
    return value;
}