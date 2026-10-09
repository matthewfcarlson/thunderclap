class Ref { public: virtual void f0(); virtual void f1(); };
class pure3d_d3dToonVertexShader { public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d_d3dToonVertexShader* vfunc_3(unsigned char); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
 char pad[0x90]; Ref* m94; Ref* m98; void helper(); };
extern char toon_vftable;
void thunk_FUN_00267090(pure3d_d3dToonVertexShader*);
pure3d_d3dToonVertexShader* pure3d_d3dToonVertexShader::vfunc_3(unsigned char p) {
 Ref* r = m98;
 *(void**)this = &toon_vftable;
 if (r) r->f1();
 r = m94;
 if (r) r->f1();
 helper();
 if (p & 1) thunk_FUN_00267090(this);
 return this;
}