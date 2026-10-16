// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000b9470 @ 0x000b9470
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Vertex_b9470 {
    float x;
    float y;
    float z;
};
class Mesh_b9470 {
  public:
    char pad0[8];
    Vertex_b9470* verts;
    char pad1[4];
    unsigned int* colors;
    void FUN_0008ef00();
};
class Texture {
  public:
    char pad[0x10];
    int handle;
};
class Gfx {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int mode);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Mesh_b9470* v30(int handle, int a, int b, int c, int d);
    virtual void v31(Mesh_b9470* m);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int on);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int on);
};
class Layer_b9470 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
class Viewport_b9470 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
struct Canvas {
    Layer_b9470* layer;
};

void __stdcall FUN_000b9470(unsigned int alpha, Texture* texture) {
    float width = (float)(*(Viewport_b9470**)&DAT_0052c2a4)->v7();
    float height = (float)(*(Viewport_b9470**)&DAT_0052c2a4)->v6();
    if (alpha > 0xff)
        alpha = 0xff;
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    DAT_0052c2a8->v54(0);
    DAT_0052c2a8->v58(0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
    unsigned int color = alpha << 24;
    Mesh_b9470* mesh = DAT_0052c2a8->v30(texture->handle, 1, 0x2020, 4, 0);
    *mesh->colors = color;
    mesh->verts->x = 0.0f;
    mesh->verts->y = height;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    *mesh->colors = color;
    mesh->verts->x = 0.0f;
    mesh->verts->y = 0.0f;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    *mesh->colors = color;
    mesh->verts->x = width;
    mesh->verts->y = height;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    *mesh->colors = color;
    mesh->verts->x = width;
    mesh->verts->y = 0.0f;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    DAT_0052c2a8->v31(mesh);
    DAT_0052c2a8->v24(saved);
    DAT_0052c2a8->v54(1);
    DAT_0052c2a8->v58(1);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
}
