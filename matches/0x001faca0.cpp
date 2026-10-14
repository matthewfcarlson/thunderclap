void __cdecl DestroyMember(void*);
void __cdecl DeleteObject(void*);
extern char CDataHandlerObject_vftable;
extern char IRefCount_vftable_1faca0;

class CDataHandlerObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* vfunc_2(unsigned char flag);
    char pad[8];
};

void* CDataHandlerObject::vfunc_2(unsigned char flag) {
    *(void**)this = (void*)&CDataHandlerObject_vftable;
    DestroyMember(*(void**)((char*)this + 12));
    *(void**)this = (void*)&IRefCount_vftable_1faca0;
    if (flag & 1) {
        DeleteObject(this);
    }
    return this;
}
