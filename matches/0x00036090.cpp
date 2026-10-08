class Target { char pad[0x1b14]; public: float value; };
float __fastcall TargetFunction(Target* self) { return self->value; }