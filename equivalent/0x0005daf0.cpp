// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// CCollisionTrack::vfunc_10 @ 0x0005daf0
extern char DAT_00494b44[];
extern char DAT_00494b60[];
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
void* __cdecl FUN_0008d690(unsigned size);
struct Index_5daf0 { int FUN_0027b200(unsigned lo, unsigned hi); };
struct Lookup_5daf0 { Index_5daf0* FUN_002226b0(); };
struct Owner_5daf0 { Lookup_5daf0* FUN_00059a40(); };
struct Holder_5daf0 { Owner_5daf0* FUN_000592a0(); };
struct CollisionItem { CollisionItem* FUN_00019380(void* a, void* self, Holder_5daf0* h, int index); };
class CCollisionTrack {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual CollisionItem* vfunc_10(void* a, void* b, void* c);
    virtual void vfunc_11();
    char pad[0x14];
    unsigned idLo, idHi;
};
CollisionItem* CCollisionTrack::vfunc_10(void* a, void*, void* c) {
    Holder_5daf0* h = (Holder_5daf0*)FUN_00344e74(c, 0, DAT_00494b44, DAT_00494b60, 0);
    Lookup_5daf0* lk = h ? h->FUN_000592a0()->FUN_00059a40() : 0;
    if (!lk) return 0;
    int index = lk->FUN_002226b0()->FUN_0027b200(idLo, idHi);
    if (index == 0xffff) return 0;
    CollisionItem* item = (CollisionItem*)FUN_0008d690(0x4c);
    if (!item) return 0;
    return item->FUN_00019380(a, this, h, index);
}
