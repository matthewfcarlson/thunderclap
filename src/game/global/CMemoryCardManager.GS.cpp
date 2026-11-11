// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008c570..0x0008ceb0 (kind game, layer game, confidence medium), dominant class CMemoryCardManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f8087876 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8087876 {} using namespace fn_f8087876;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8087876 {
struct Record_8c590 { unsigned int words[66]; };
struct Source_8c590 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14();
 virtual void first(const char*, Record_8c590*);
 virtual void next(Record_8c590*);
 virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22();
 virtual int error();
};
struct Entry_8c590 { Source_8c590* source; char padding[196]; };
struct Object {
  public:
    virtual void _m_vf0();
    virtual void release();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void getState(int*);
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual int value();
    virtual void update();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void _m_vf27();
    virtual void _m_vf28();
    virtual void _m_vf29();
    virtual void _m_vf30();
    virtual void _m_vf31();
    virtual void _m_vf32();
    virtual void _m_vf33();
    virtual void _m_vf34();
    virtual void _m_vf35();
    virtual void query(Object**, char*, int,int,int,int,int);
    char _m_pad_4[0x4];
    Entry_8c590* entries;
    int target(int index, int selected, Record_8c590* output);
};
namespace XAPILIB {
void __stdcall XLaunchNewImageA(const char *, void *);
}
struct Item_8c680 {
virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual signed char *f39();
};
struct Entry_8c680 { Item_8c680 *item; char padding[196]; };
struct LaunchData_8c680 { int mode; int reserved; int code; int size; char rest[0xbf0]; };
struct Owner_8c680 { char padding[8]; Entry_8c680 *entries; void FUN_0008c680(int index); };
struct State_8c920 { Object* object; char pad[0x58]; int state; char pad2[0x54]; int values[5]; };
struct Manager_8c920 { char pad[8]; State_8c920* data; int FUN_0008c590(int, unsigned, int*); void target(); };
struct CreateParams_8ca70 {
    void* buffer;
    int a;
    int b;
    int c;
    int d;
    int e;
};
class Obj_8ca70 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(int a, int b, int c);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual int v58();
    virtual int v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90(Obj_8ca70** out, CreateParams_8ca70 p);
};
struct Slot_8ca70 {
    Obj_8ca70* obj;
    Obj_8ca70* aux;
    char pad08[0xc0];
};
extern "C" int FUN_0026b800(int a, int b, char* buf, int c, int d, int e, int f);
class Manager_8ca70 {
public:
    char pad00[8];
    Slot_8ca70* slots;
    int FUN_0008c590(int index, int a, int* status);
    int FUN_0008ca70(int index, int arg1, int arg2, int arg3, int arg4);
};
struct Engine_8cbe0 {
    void FUN_001eb870();
    void FUN_001eb890();
};
} // namespace fn_f8087876
struct Singleton_4dd6ec {
    Engine_8cbe0 *FUN_000862e0();
};
namespace fn_f8087876 {
extern "C" void *FUN_0008d690(unsigned int size);
extern "C" int __cdecl FUN_00266da0(int mode);
void __cdecl FUN_0026b800(char *buf, int a, int b, int c, int d, int e, int f);
class SubObj_8cbe0 {
public:
    virtual void v0();
    virtual void Release();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(int a, int b, int c);
    virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21();
    virtual void *v22();
    virtual char v23();
};
class Source;
class Stage_8cbe0 {
public:
    virtual void v0();
    virtual void Release();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21();
};
class Slot_8cbe0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual int v22();
    virtual void *v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(SubObj_8cbe0 **out, char *buf, int a, int b, void *c, int d, int e);
};
struct Entry_8cbe0 {
    Slot_8cbe0 *slot;
    Stage_8cbe0 *stage;
    char pad[0xc8 - 8];
};
class Loader_8cbe0 {
public:
    void *FUN_0008cbe0(int index, int a, int b, int c, int d);

    char pad0[4];
    int param;
    Entry_8cbe0 *entries;
};


// 0x0008c590 FUN_0008c590 (226 B): equivalent/0x0008c590.cpp
// sym: ?target@Object@fn_f8087876@@QAEHHHPAURecord_8c590@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 15895 inputs, branch coverage 8/8)
// FUN_0008c590 @ 0x0008c590
int Object::target(int index,int selected,Record_8c590* output) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 Record_8c590 records[5]; Source_8c590* source=entries[index].source;
 int result=0;
 for(unsigned int i=0;i<5;++i) {
  if(i==0) source->first(((const char*)&DAT_003f335c),&records[i]); else source->next(&records[i]);
  result=source->error();
  if(result) { output->words[0]=2; break; }
  if(i==(unsigned int)selected) { *output=records[i]; break; }
 }
 return result;
}


// 0x0008c680 FUN_0008c680 (110 B): equivalent/0x0008c680.cpp
// sym: ?FUN_0008c680@Owner_8c680@fn_f8087876@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 0/0)
// FUN_0008c680 @ 0x0008c680
void Owner_8c680::FUN_0008c680(int index) {
LaunchData_8c680 data;
signed char *value = entries[index].item->f39();
data.mode = 2;
data.reserved = 0;
data.code = *value;
data.size = 4;
XAPILIB::XLaunchNewImageA(0, &data);
}


// 0x0008c920 FUN_0008c920 (261 B): equivalent/0x0008c920.cpp
// sym: ?target@Manager_8c920@fn_f8087876@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 19964 inputs, branch coverage 15/16, incomplete)
// FUN_0008c920 @ 0x0008c920
void Manager_8c920::target() {
 struct Workspace { Object* item; int status; char buffer[260];  } work;
 Object* root = data->object;
 if(root) {
 root->getState(&data->state);
 root->update();
 if(data->state == 0) {
 for(unsigned i=0;i<5;++i) {
 work.item=0;
 data->values[i]=1;
 int result=FUN_0008c590(0,i,&work.status);
 if(result) data->values[i]=result;
 else {
 if(work.status==2) data->values[i]=1;
 if(work.status==3) {
 root->query(&work.item,work.buffer,0,0,0,0,1);
 if(work.item) {
 data->values[i]=work.item->value();
 work.item->update();
 if(work.item) work.item->release();
 }
 }
 }
 }
 }
 }
}


// 0x0008ca70 FUN_0008ca70 (356 B): equivalent/0x0008ca70.cpp
// sym: ?FUN_0008ca70@Manager_8ca70@fn_f8087876@@QAEHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 16099 inputs, branch coverage 21/22, incomplete)
// FUN_0008ca70 @ 0x0008ca70
int Manager_8ca70::FUN_0008ca70(int index, int arg1, int arg2, int arg3, int arg4)
{
    struct {
        Obj_8ca70* created;
        int status;
        char buf[0x104];
    } f;
    int result;
    Obj_8ca70* obj = slots[index].obj;
    obj->v58();
    if (slots[index].aux) {
        slots[index].aux->v54();
        Obj_8ca70** auxSlot = &slots[index].aux;
        if (*auxSlot) {
            (*auxSlot)->v04();
            *auxSlot = 0;
        }
    }
    result = FUN_0008c590(index, arg1, &f.status);
    if (result == 0) {
        if (f.status == 2) {
            result = 1;
        } else {
            if (arg4 != 0)
                FUN_0026b800(arg4, 2, f.buf, 1, 0x2e, 0x40, 0);
            CreateParams_8ca70 p;
            f.created = 0;
            p.buffer = f.buf;
            p.a = 0;
            p.b = 0;
            p.c = 0;
            p.d = 0;
            p.e = 1;
            obj->v90(&f.created, p);
            result = obj->v5c();
            if (result == 1)
                result = 0xc;
            if (f.created) {
                if (result == 0) {
                    result = f.created->v58();
                    if (result == 0 && (char)f.created->v5c()) {
                        f.created->v24(arg2, arg3, 1);
                        result = f.created->v58();
                    }
                }
                if (f.created)
                    f.created->v04();
            }
        }
    }
    return result;
}


// 0x0008cbe0 FUN_0008cbe0 (405 B): equivalent/0x0008cbe0.cpp
// sym: ?FUN_0008cbe0@Loader_8cbe0@fn_f8087876@@QAEPAXHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 10398 inputs, branch coverage 15/16, incomplete)
// FUN_0008cbe0 @ 0x0008cbe0
void *Loader_8cbe0::FUN_0008cbe0(int index, int a, int b, int c, int d)
{
    char buf[0x100];
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb870();
    Slot_8cbe0 *slot = entries[index].slot;
    slot->v22();
    if (entries[index].stage) {
        entries[index].stage->v21();
        Stage_8cbe0 **slotStage = &entries[index].stage;
        Stage_8cbe0 *stage = *slotStage;
        if (stage) {
            stage->Release();
            *slotStage = 0;
        }
    }
    int prev = FUN_00266da0(1);
    int *state = (int *)FUN_0008d690(8);
    state[0] = 0;
    state[1] = 0;
    FUN_00266da0(prev);
    FUN_0026b800(buf, 1, d, 2, 0x2e, 0x100, 0);
    SubObj_8cbe0 *sub = 0;
    slot->v36(&sub, buf, 1, 3, state, param, 1);
    void *result = slot->v23();
    FUN_0008d330(state);
    if (sub) {
        if (!result) {
            result = sub->v22();
            if (!result && sub->v23()) {
                sub->v10(b, c, 1);
                result = sub->v22();
                if (!result) {
                    sub->v14();
                    result = sub->v22();
                }
            }
        }
        if (sub) {
            sub->Release();
            sub = 0;
        }
    }
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb890();
    return result;
}

} // namespace fn_f8087876

// 0x0008cd80 FUN_0008cd80 (187 B): equivalent/0x0008cd80.cpp [wrapped: conflict: Object]
// sym: ?FUN_0008cd80@Manager_8cd80@fn_0008cd80@@QAEHHH@Z
namespace fn_0008cd80 {
// STATUS: equivalent (tools/equiv.py level 3: 18773 inputs, branch coverage 8/8)
// FUN_0008cd80 @ 0x0008cd80
// cl-flags: /GS
struct Object {
 virtual void v0(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void apply(void*); virtual void v18(); virtual void v19(); virtual void v20(); virtual void stop(); virtual void begin(); virtual int finish();
};
struct Entry_8cd80 { Object* primary; Object* secondary; char padding[192]; };
struct Output_8cd80 { int type; char data[260]; };
struct Manager_8cd80 {
 char pad[8]; Entry_8cd80* entries;
 int FUN_0008c590(int index, int arg, Output_8cd80* output);
 int FUN_0008cd80(int index,int arg);
};
int Manager_8cd80::FUN_0008cd80(int index,int arg) {
 Output_8cd80 output;
 Object* original = entries[index].primary;
 original->begin();
 if(entries[index].secondary) {
 entries[index].secondary->stop();
 Object** slot = &entries[index].secondary;
 if(*slot) { (*slot)->release(); *slot = 0; }
 }
 int result = FUN_0008c590(index,arg,&output);
 if(result == 0) {
 if(output.type != 3) result = 1;
 else { original->apply(output.data); result = original->finish(); }
 }
 return result;
}
} // namespace fn_0008cd80

