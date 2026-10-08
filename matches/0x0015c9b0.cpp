class ClimbLocomotion4Action { public: char pad[0x48]; void* field; void vfunc_8(void* out); };
void ClimbLocomotion4Action::vfunc_8(void* out) { *(void**)out = *(void**)((char*)this->field + 0x14); }