extern "C" void* memset(void*, int, unsigned int);
class ShadowTraversal { public: char pad[0x38]; unsigned int count; void* buffer; void vfunc_5(); };
void ShadowTraversal::vfunc_5() { memset(buffer, 0, count * 20); count = 0; }