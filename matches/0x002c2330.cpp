class IRefCount { public: virtual void Release(int); };
class TextureLoader { public: virtual void v0(); char pad[0x10]; void* mTexture; void* mOther; };
struct Holder { char pad[0x14]; void* p; void* q; };
void __fastcall FUN_002ae910(void*);
void __cdecl thunk_FUN_00267090(void*);
extern int textureVtable, refVtable;
void __fastcall FUN_002c2330(TextureLoader* self) {
    void* p=((Holder*)self)->p;
    *(int**)self=&textureVtable;
    if(p){ FUN_002ae910(p); thunk_FUN_00267090(p); }
    if(((Holder*)self)->q) ((IRefCount*)((Holder*)self)->q)->Release(1);
    *(int**)self=&refVtable;
}