extern void* __cdecl Alloc(unsigned int);
extern int KeywordWaitVtable;
class Helper { public: void Init(); };
class SetupObj { public: void Setup(); };
struct KeywordWaitTrack { unsigned int vptr; unsigned int pad04; int field08; int field0c; float field10; char pad14[4]; char field18[8]; char field20; };
KeywordWaitTrack* __cdecl target() {
    KeywordWaitTrack* p = (KeywordWaitTrack*)Alloc(0x28);
    if (p) {
        ((Helper*)p)->Init();
        p->vptr = (unsigned int)&KeywordWaitVtable;
        p->field0c = 0;
        p->field10 = -1.0f;
        ((SetupObj*)((char*)p + 0x18))->Setup();
        p->field20 = 0;
        p->field08 = 1;
        return p;
    }
    return 0;
}