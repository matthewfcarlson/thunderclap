class IFile { public: virtual void a(); virtual void b(); };
class IRefCount { public: virtual void c(); virtual void d(); };
class IMutable { public: virtual void e(); virtual void f(); };
class File : public IFile, public IRefCount, public IMutable {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual File* vfunc_25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
};
File* File::vfunc_25() { return (File*)((char*)this + 0x1e); }