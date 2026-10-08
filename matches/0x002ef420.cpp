extern const float gOne;
struct Inner { char pad[0x34]; float value; };
struct Holder { char pad[0x20]; Inner* inner; };
struct Obj { char pad[0x74]; Holder* holder; };
float __fastcall FUN_002ef420(Obj* self) { if (self->holder) return self->holder->inner->value; return gOne; }
