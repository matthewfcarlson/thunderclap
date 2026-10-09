typedef unsigned char byte;
typedef unsigned int u32;
void thunk_FUN_00267090(void*);
struct CDataHandlerObject { virtual void f0(); virtual void f1(); virtual CDataHandlerObject* vfunc_2(byte); u32 pad; u32 field; };
CDataHandlerObject* CDataHandlerObject::vfunc_2(byte param_2) {
  *(u32*)this = 0x42501c;
  thunk_FUN_00267090(*(void**)((char*)this + 0xc));
  *(u32*)this = 0x3f6098;
  if (param_2 & 1) thunk_FUN_00267090(this);
  return this;
}