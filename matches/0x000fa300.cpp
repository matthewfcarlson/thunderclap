typedef unsigned char byte;
void thunk_FUN_00267090(void*);
namespace DollyScript {
extern void* CTokenString_vftable[];
extern void* CScriptToken_vftable[];
class CScriptToken { public: void* vptr; char pad[0x0c]; };
class CTokenString : public CScriptToken {
public:
 void* mString;
 CTokenString* vfunc_0(byte);
};
CTokenString* CTokenString::vfunc_0(byte param_2) {
 vptr = CTokenString_vftable;
 if (mString) { thunk_FUN_00267090(mString); mString = 0; }
 vptr = CScriptToken_vftable;
 if (param_2 & 1) thunk_FUN_00267090(this);
 return this;
}
}