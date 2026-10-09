class CGameDataHandler;
class DataHandler { public: class ObjectCreator { public: virtual CGameDataHandler *vfunc_0(unsigned char); virtual void vfunc_1(); }; };
class Ref { public: virtual void Release(int); };
extern void *gGameVtable;
extern void *gBaseVtable;
class CGameDataHandler : public DataHandler::ObjectCreator { public: virtual CGameDataHandler *vfunc_0(unsigned char); virtual void vfunc_1(); Ref *mRef; };
void thunk_FUN_00267090(CGameDataHandler *);
CGameDataHandler * CGameDataHandler::vfunc_0(unsigned char flags) { *(void **)this = &gGameVtable; if (mRef) mRef->Release(1); *(void **)this = &gBaseVtable; if (flags & 1) thunk_FUN_00267090(this); return this; }