// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 16/16)
// pure3d::PrimGroupStreamed::vfunc_6 @ 0x002df5a0
struct Resource { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(void*); };
struct Mesh { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual int v11(); };
struct Holder { char pad[16]; Mesh* mesh; };
struct Stream { char pad[8]; unsigned flags; unsigned fallback; unsigned count; };
struct Renderer { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void* v30(Mesh*,unsigned,unsigned,unsigned,int); virtual void v31(void*); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual Resource* v89(int); };
extern Renderer* DAT_0052c2a8;
namespace pure3d { struct PrimGroupStreamed { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void vfunc_6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(void*); char pad[60]; Holder* holder; unsigned kind; char pad2[16]; void* binding; Stream* stream; }; }
void pure3d::PrimGroupStreamed::vfunc_6() {
 unsigned flags = stream->flags & 0xfffffe7f;
 if(binding) { Resource* r=DAT_0052c2a8->v89(0x106); if(r) r->v6(binding); }
 Mesh* mesh=holder ? holder->mesh : 0;
 int n=mesh->v11();
 unsigned count=stream->count;
 for(int i=0;i<n;++i) { unsigned size=count; if(!size) size=stream->fallback; void* p=DAT_0052c2a8->v30(mesh,kind,flags,size,i); v12(p); DAT_0052c2a8->v31(p); }
 if(binding) { Resource* r=DAT_0052c2a8->v89(0x106); if(r) r->v6(0); }
}
