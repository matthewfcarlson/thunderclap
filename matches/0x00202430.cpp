class Helper { public: void Init(); };
extern void* vtable;
void __cdecl thunk_FUN_00267090(void*);
class CWorldCollisionManager { public: void* vft; char pad4[12]; void* ptr; char pad14[12]; Helper helper; void Init(); };
void CWorldCollisionManager::Init() {
    vft = &vtable;
    helper.Init();
    if (ptr) thunk_FUN_00267090((char*)ptr - 4);
}