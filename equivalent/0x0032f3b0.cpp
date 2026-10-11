// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 26/26)
// pure3d::d3dRefractVertexShader::vfunc_24 @ 0x0032f3b0
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(int,const void*); void __fastcall D3DDevice_SetVertexShaderConstant4(int,const void*); void __stdcall D3DDevice_GetTransform(int,void*); void __stdcall D3DDevice_GetLight(int,void*); }
struct Matrix { float m[16]; void FUN_0022ca90(const Matrix*,const Matrix*); void FUN_0022cc10(const Matrix*,const Matrix*); void FUN_0022c0b0(); };
struct V { float x,y,z,w; };
// equiv-conv: FUN_0032ee30 ecx stack
void FUN_0032ee30(V*,unsigned int);
struct Material { unsigned int diffuse,specular,ambient,emissive; float power; };
struct Light { unsigned int type; V diffuse,specular,ambient; float position[3]; V direction; float rest[6]; };
struct Surface { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int v6(); virtual int v7(); char pad[0x48c]; unsigned height,width; };
struct Context { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual unsigned* v36(unsigned*); char pad[0x150]; Surface* surface; void FUN_00321dc0(int*,int); };
namespace pure3d { struct d3dRefractVertexShader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(Material*); virtual void v22(); virtual void v23(); virtual void vfunc_24(); char pad0[12]; Context* context; char pad1[0x24]; unsigned alpha; char pad2[0x41]; unsigned char flag; char pad3[10]; float scale,intensity; }; }
void pure3d::d3dRefractVertexShader::vfunc_24() {
 struct Scratch { unsigned packed; int surfaceHeight; float height; V result; } scratch;
 float viewport[4]={640.f,480.f,1.f,1.f};
 viewport[0]=(float)context->surface->width; viewport[1]=(float)context->surface->height;
 float width=(float)context->surface->width; int sw=context->surface->v7();
 float uv[4]; uv[0]=width/sw*scale;
 scratch.height=(float)context->surface->height; scratch.surfaceHeight=context->surface->v6(); uv[1]=scratch.height/scratch.surfaceHeight*scale; uv[2]=uv[3]=0;
 float half[4]={0.5f,0.5f,0.5f,0.5f}; float one[4]={1,1,1,1};
 scratch.packed=255-alpha; intensity=(float)scratch.packed*intensity*0.003921568859368563f; one[3]=intensity-0.3f;
 if(flag) { D3D8::D3DDevice_SetVertexShaderConstant1(188,uv); D3D8::D3DDevice_SetVertexShaderConstant1(189,half); D3D8::D3DDevice_SetVertexShaderConstant1(190,viewport); D3D8::D3DDevice_SetVertexShaderConstant1(191,one); return; }
 Matrix projection,world,view,pw,pwv,inverse,invproj;
 D3D8::D3DDevice_GetTransform(6,&projection); D3D8::D3DDevice_GetTransform(0,&world); D3D8::D3DDevice_GetTransform(1,&view);
 pw.FUN_0022ca90(&projection,&world); pwv.FUN_0022cc10(&pw,&view); inverse=pwv; inverse.FUN_0022c0b0(); invproj=projection; invproj.FUN_0022c0b0();
 D3D8::D3DDevice_SetVertexShaderConstant4(0x62,&inverse); D3D8::D3DDevice_SetVertexShaderConstant4(0x66,&invproj);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,viewport); D3D8::D3DDevice_SetVertexShaderConstant1(0x6c,uv); D3D8::D3DDevice_SetVertexShaderConstant1(0x6d,half);
 int ids[4]; float coeff[4]={0,1,256,0.5f}; context->FUN_00321dc0(ids,0);
 Light lights[3]; D3D8::D3DDevice_GetLight(ids[0]==-1?0:ids[0],&lights[0]); D3D8::D3DDevice_GetLight(ids[1]==-1?0:ids[1],&lights[1]); D3D8::D3DDevice_GetLight(ids[2]==-1?0:ids[2],&lights[2]);
 Material material; v21(&material); float zero[4]={0,0,0,0}; V specular,diffuse,ambient,global; V& result=scratch.result;
 FUN_0032ee30(&specular,material.specular); FUN_0032ee30(&diffuse,material.diffuse); FUN_0032ee30(&result,material.emissive); FUN_0032ee30(&ambient,material.ambient);
 unsigned* p=context->v36(&scratch.packed); FUN_0032ee30(&global,*p);
 if(result.w==0.0f) { result.w=diffuse.w; diffuse.w=0; }
 specular.w=material.power;
 result.x=global.x*ambient.x+result.x; result.y=global.y*ambient.y+result.y; result.z=global.z*ambient.z+result.z; result.w=global.w*ambient.w+result.w;
 D3D8::D3DDevice_SetVertexShaderConstant1(0x60,coeff); D3D8::D3DDevice_SetVertexShaderConstant1(0x6e,&diffuse); D3D8::D3DDevice_SetVertexShaderConstant1(0x6f,&specular); D3D8::D3DDevice_SetVertexShaderConstant1(0x70,&result);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x71,&lights[0].direction); D3D8::D3DDevice_SetVertexShaderConstant1(0x72,ids[0]==-1?(void*)zero:(void*)&lights[0].diffuse);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x73,&lights[1].direction); D3D8::D3DDevice_SetVertexShaderConstant1(0x74,ids[1]==-1?(void*)zero:(void*)&lights[1].diffuse);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x75,&lights[2].direction); D3D8::D3DDevice_SetVertexShaderConstant1(0x76,ids[2]==-1?(void*)zero:(void*)&lights[2].diffuse); D3D8::D3DDevice_SetVertexShaderConstant1(0x79,one);
}