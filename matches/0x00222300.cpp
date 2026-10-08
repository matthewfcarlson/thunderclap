class PartitionDriver { char pad[0x1c]; public: int vfunc_8(); };
int PartitionDriver::vfunc_8() { return *(int*)((char*)this + 0x1c); }