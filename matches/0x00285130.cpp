class BlendFrameController { public: char pad[0x28]; unsigned int count; float vfunc_11(); };
extern const float zero;
float BlendFrameController::vfunc_11() { if (count > 0) return *(float*)(*(int*)((char*)this + count * 0x2c + 0x28) + 0x10); return zero; }
