// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_00208210 @ 0x00208210
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
class CWorldStreamManager;

void* FUN_0008d690(hulk_uintptr size);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
inline void* operator new(unsigned int, void* p) throw() { return p; }

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void* get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<int> { static const void* get() { return ((char*)&DAT_0048e134); } };

class __declspec(novtable) MethodBase_208210 {
  public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase_208210(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_208210 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) : MethodBase_208210(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argType = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T* owner;
};

struct ClosureAdjacent {
    ClosureAdjacent* FUN_00205e30(const char* name, CWorldStreamManager* owner, int (CWorldStreamManager::*fn)(int, int));
};

class CWorldStreamManager {
  public:
    CWorldStreamManager();
    virtual void vfn0();

    class CMemoryPool {
      public:
        CMemoryPool() {
            state = 0;
            flagA = 0;
            word26 = 0;
            f2c = 0;
            f30 = 0;
            f34 = 0x80;
            f38 = 0;
        }
        virtual void vfn0();
        char state;
        char flagA;
        char pad6[0x26 - 6];
        short word26;
        char pad28[4];
        int f2c;
        int f30;
        int f34;
        int f38;
    };

    void FUN_002036c0(int);
    void FUN_002036e0(int);
    void FUN_00203780(int);
    void FUN_00203e00(int);
    void FUN_002071e0(int);
    int FUN_002042f0(int);
    int FUN_00204410(int);
    bool FUN_00204440(int);
    int FUN_00204320(int);
    bool FUN_00204350(float*);
    bool FUN_00204200(float*);
    const char* FUN_00203740(float*);
    int FUN_002042a0(int, int);
    int FUN_002043e0();
    bool FUN_001e8710();
    void FUN_00207ba0();
    void FUN_00207d80();
    void FUN_00207960();
    void FUN_00207b90();
    void FUN_002080b0();
    int FUN_00078b40();
    int FUN_002036f0();

    char pad04[0x44 - 4];
    int f44;
    CMemoryPool pools[20];
    CMemoryPool poolA;
    CMemoryPool poolB;
    int f570, f574, f578, f57c, f580;
    char pad584[4];
    int f588, f58c, f590, f594, f598, f59c;
    char pad5a0[4];
    int buf5a4[256];
    int f9a4, f9a8;
    char pad9ac[0xa4c - 0x9ac];
    int fa4c;
    char padA50[0xaa0 - 0xa50];
    int faa0;
    char name[0x20];
    char nameTerm;
    char padAC5[0xae4 - 0xac5];
    int fae4, fae8, faec;
    char faf0, faf1, faf2, faf3, faf4, faf5;
    char padAF6[2];
    int faf8, fafc;
};

struct Registry_208210 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_00206c90(const char* name, CWorldStreamManager* owner, bool (CWorldStreamManager::*fn)(float*));
    void FUN_00206cf0(const char* name, CWorldStreamManager* owner, bool (CWorldStreamManager::*fn)(float*));
    void FUN_00206d50(const char* name, CWorldStreamManager* owner, const char* (CWorldStreamManager::*fn)(float*));
    void FUN_00206e60(const char* name, CWorldStreamManager* owner, int (CWorldStreamManager::*fn)());
    void FUN_00206f20(const char* name, CWorldStreamManager* owner, bool (CWorldStreamManager::*fn)());
    void FUN_00206f90(const char* name, CWorldStreamManager* owner, void (CWorldStreamManager::*fn)());
    void FUN_00207000(const char* name, CWorldStreamManager* owner, void (CWorldStreamManager::*fn)());
};
Registry_208210* FUN_001d4c90();

CWorldStreamManager::CWorldStreamManager()
{
    f44 = 0;
    f588 = 0;
    f58c = 0;
    f590 = 0;
    f594 = 0;
    f598 = 0;
    f59c = 0;
    f9a4 = 0;
    f9a8 = 0;
    fa4c = 0;
    faa0 = 0;
    fae4 = 0;
    fae8 = 0;
    faec = 0;
    faf0 = 0;
    faf1 = 0;
    faf2 = 0;
    faf3 = 0;
    faf4 = 0;
    faf5 = 0;
    faf8 = 0;
    fafc = 0;

    Registry_208210* reg = FUN_001d4c90();
    if (reg) {
        void* mem;

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, void, int>* setSync = 0;
        if (mem)
            setSync = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_SetSynchronous", this, &CWorldStreamManager::FUN_002036c0);
        reg->FUN_001d3b70("wsm_SetSynchronous", setSync);

        reg->FUN_00206c90("wm_IsPointInARoom", this, &CWorldStreamManager::FUN_00204350);

        reg->FUN_00206cf0("wm_FindRoomWithPoint", this, &CWorldStreamManager::FUN_00204200);

        reg->FUN_00206d50("wm_GetUniqueName", this, &CWorldStreamManager::FUN_00203740);

        mem = FUN_0008d690(0x24);
        ClosureAdjacent* adjacent = 0;
        if (mem)
            adjacent = ((ClosureAdjacent*)mem)->FUN_00205e30("wm_GetAdjacentRoom", this, &CWorldStreamManager::FUN_002042a0);
        reg->FUN_001d3b70("wm_GetAdjacentRoom", adjacent);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, int, int>* numAdjacent = 0;
        if (mem)
            numAdjacent = new (mem) Closure1<CWorldStreamManager, int, int>("wm_GetNumAdjacentRoom", this, &CWorldStreamManager::FUN_002042f0);
        reg->FUN_001d3b70("wm_GetNumAdjacentRoom", numAdjacent);

        reg->FUN_00206e60("wm_GetNumRoomsLoaded", this, &CWorldStreamManager::FUN_002043e0);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, int, int>* loadedNum = 0;
        if (mem)
            loadedNum = new (mem) Closure1<CWorldStreamManager, int, int>("wm_GetLoadedRoomNum", this, &CWorldStreamManager::FUN_00204410);
        reg->FUN_001d3b70("wm_GetLoadedRoomNum", loadedNum);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, bool, int>* roomLoaded = 0;
        if (mem)
            roomLoaded = new (mem) Closure1<CWorldStreamManager, bool, int>("wm_IsRoomLoaded", this, &CWorldStreamManager::FUN_00204440);
        reg->FUN_001d3b70("wm_IsRoomLoaded", roomLoaded);

        reg->FUN_00206f20("wsm_IsLoading", this, &CWorldStreamManager::FUN_001e8710);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, void, int>* setRoom = 0;
        if (mem)
            setRoom = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_SetCurrentRoom", this, &CWorldStreamManager::FUN_002036e0);
        reg->FUN_001d3b70("wsm_SetCurrentRoom", setRoom);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, void, int>* loadRoom = 0;
        if (mem)
            loadRoom = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_LoadRoomTemp", this, &CWorldStreamManager::FUN_00203780);
        reg->FUN_001d3b70("wsm_LoadRoomTemp", loadRoom);

        reg->FUN_00206f90("wsm_LoadRoomTempFlush", this, &CWorldStreamManager::FUN_00207ba0);

        reg->FUN_00206f90("wsm_UnloadTempRooms", this, &CWorldStreamManager::FUN_00207d80);

        reg->FUN_00207000("wsm_LoadTempFile", this, &CWorldStreamManager::FUN_00207960);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, void, int>* unloadTemp = 0;
        if (mem)
            unloadTemp = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_UnloadTempFile", this, &CWorldStreamManager::FUN_00203e00);
        reg->FUN_001d3b70("wsm_UnloadTempFile", unloadTemp);

        reg->FUN_00206f90("wsm_SetupTempMemory", this, &CWorldStreamManager::FUN_00207b90);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, void, int>* setupTempEx = 0;
        if (mem)
            setupTempEx = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_SetupTempMemoryEx", this, &CWorldStreamManager::FUN_002071e0);
        reg->FUN_001d3b70("wsm_SetupTempMemoryEx", setupTempEx);

        reg->FUN_00206f90("wsm_ReleaseTempMemory", this, &CWorldStreamManager::FUN_002080b0);

        reg->FUN_00206e60("wsm_GetCurrentRoom", this, &CWorldStreamManager::FUN_00078b40);

        reg->FUN_00206e60("wsm_GetLastRoom", this, &CWorldStreamManager::FUN_002036f0);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldStreamManager, int, int>* districtFromRoom = 0;
        if (mem)
            districtFromRoom = new (mem) Closure1<CWorldStreamManager, int, int>("wsm_GetDistrictFromRoom", this, &CWorldStreamManager::FUN_00204320);
        reg->FUN_001d3b70("wsm_GetDistrictFromRoom", districtFromRoom);

        strncpy(name, "hulk", 0x20);
        nameTerm = 0;
        f578 = 0;
        f57c = 0;
        f580 = 0;
        for (int i = 0; i < 256; i++)
            buf5a4[i] = 0;
        f570 = 0;
        f574 = 0;
    }
}
