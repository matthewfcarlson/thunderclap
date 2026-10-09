typedef unsigned char u8;
extern void thunk_FUN_00267090(void*);
class CStaticAllocator {
public:
 virtual CStaticAllocator* vfunc_0(u8);
 char pad[0x0c];
 void* p10;
 void* p14;
};
CStaticAllocator* CStaticAllocator::vfunc_0(u8 param_2) {
 void* a = p14;
 *(void**)this = (void*)0x400c1c;
 thunk_FUN_00267090(a);
 thunk_FUN_00267090(p10);
 if (param_2 & 1) thunk_FUN_00267090(this);
 return this;
}