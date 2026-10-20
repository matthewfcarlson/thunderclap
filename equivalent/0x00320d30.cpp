// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 58/58)
// FUN_00320d30 @ 0x00320d30
#include "gen/pure3d.h"
namespace D3D8 { struct CreationParameters { unsigned adapter; unsigned deviceType; void* focusWindow; unsigned behaviorFlags; }; extern "C" int __stdcall D3DDevice_GetCreationParameters(CreationParameters*); extern "C" int __stdcall D3D_CheckDeviceFormat(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); }
extern "C" void* __cdecl FUN_0008d690(unsigned);
struct DeviceInfo { char pad[0x42c]; unsigned format; };
struct Renderer_320d30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
 virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
 virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
 virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
 virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
 virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
 char pad[0x150]; DeviceInfo* device; char pad2[0x2c]; unsigned formats[30]; char pad3[8]; void* object;
 int FUN_00320c60(); unsigned char FUN_00320d30();
};
struct d3dPrimStream_nv_320d30 {
    void* FUN_0031bfa0(Renderer_320d30*);
};
unsigned char Renderer_320d30::FUN_00320d30() {
 D3D8::CreationParameters p;
 D3D8::D3DDevice_GetCreationParameters(&p);
 unsigned format = device->format;
 const unsigned candidates[] = {6,7,5,3,2,4,0x19,0xb,0,0x1a,0x28,0x27,7,0x3a,0x33,0x25,0x24,0xc,0xe,0xe,0xf,0xf,0x11,0x10,0x1d,0x1e,0x12,0x12};
 unsigned count=0;
 unsigned deviceType=p.deviceType;
 for (unsigned i=0;i<28;++i) {
   unsigned candidate=candidates[i];
   if (D3D8::D3D_CheckDeviceFormat(p.adapter,deviceType,format,0,3,candidate)==0) {
     formats[count]=candidate;
     formats[count+1]=0xffffffff;
     if (i!=27) ++count;
   }
 }
 ::pure3d::d3dPrimStream* allocated=(::pure3d::d3dPrimStream*)FUN_0008d690(0x160);
 object=allocated ? ((d3dPrimStream_nv_320d30*)(allocated))->FUN_0031bfa0(this) : 0;
 v99();
 FUN_00320c60();
 return 1;
}