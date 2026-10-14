// STATUS: equivalent (tools/equiv.py level 3: 2159 inputs, branch coverage 20/20)
// FUN_0029f0b0 @ 0x0029f0b0
struct Item_29f0b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(int index);
};
struct List_29f0b0 { char pad[16]; int capacity; int count; Item_29f0b0** items; };
struct Backend_29f0b0 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void setValue(int value); virtual int* getValue(List_29f0b0** output); virtual void s37(); virtual void clear(int index,int value); virtual bool has(int index);
};
extern Backend_29f0b0* DAT_0052c2a8;
struct Target_29f0b0 { char pad[16]; int capacity; void FUN_0029f0b0(List_29f0b0* list, int* value); };
void Target_29f0b0::FUN_0029f0b0(List_29f0b0* list, int* value) {
 int i=0;
 if(list) { int count=list->count; while(i<count) { if(i>=capacity || i>=list->capacity) break; Item_29f0b0* item=list->items[i]; if(!item) break; item->slot5(i); ++i; } }
 while(i<capacity) { if(!DAT_0052c2a8->has(i)) break; DAT_0052c2a8->clear(i,0); ++i; }
 int* current=DAT_0052c2a8->getValue(&list);
 if(*current!=*value) DAT_0052c2a8->setValue(*value);
}
