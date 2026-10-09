class Obj { public: virtual void f0(); virtual bool f1(int,int); virtual bool f2(int,int); };
class FEThingsBase {
public:
 virtual void v0(); virtual bool v1(int,int); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 char pad[0x1758]; Obj *thing175c; Obj *thing1760; char pad2[0xab4]; Obj *thing2218;
};
bool FEThingsBase::v1(int a,int index) { if (*((unsigned char*)this+index+0x2100)) return true; if(thing2218) return thing2218->f2(a,index); if(thing1760) return thing1760->f2(a,index); if(thing175c) return thing175c->f2(a,index); return false; }