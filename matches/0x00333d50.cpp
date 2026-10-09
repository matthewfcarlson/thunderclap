class PlayerBink { public: char pad[0x18]; int mFlag; void* mHandle; void vfunc_7(); };
void __stdcall ReleaseHandle(void*);
void PlayerBink::vfunc_7() { if (mFlag) { ReleaseHandle(mHandle); mHandle = 0; mFlag = 0; } }