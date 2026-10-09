class A { char pad[0x1c]; public: float value; void Set(float x) { if (x >= 0.0f) value = x; } };
void __fastcall FUN_00083d30(A* self, void*, float x) { if (x >= 0.0f) self->value = x; }