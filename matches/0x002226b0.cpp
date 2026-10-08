class Target { public: char pad[0x64]; struct Inner { char pad[8]; int value; } *member; };
int __fastcall FUN_002226b0(Target* self) { return self->member->value; }