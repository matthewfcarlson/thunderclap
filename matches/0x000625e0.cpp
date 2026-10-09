extern void __fastcall FUN_0027af50(void*);
extern void __fastcall FUN_00068c70(void*);
struct CSmartPropSpawnTrack {
 void* vptr;
 char p0[0x94];
 char a;
 char p1[7];
 char b;
 char p2[0x27];
 char c;
 void Dtor();
};
void CSmartPropSpawnTrack::Dtor() {
 vptr = (void*)0x3fafd8;
 FUN_0027af50(&c);
 FUN_0027af50(&b);
 FUN_0027af50(&a);
 FUN_00068c70(this);
}
