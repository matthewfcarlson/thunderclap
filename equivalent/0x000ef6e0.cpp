// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 12/12)
// FEScreenBase::vfunc_14 @ 0x000ef6e0
struct Settings_ef6e0 {
 char pad0[0x20]; unsigned value; char pad24[0xc]; unsigned z; unsigned x; float y; char pad3c[0x80]; unsigned char enabled;
};
struct Manager_ef6e0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(unsigned); virtual void slot41(); virtual void slot42(unsigned); virtual Settings_ef6e0* slot43();
 char pad[0x1850]; unsigned items[2];
};
struct Widget_ef6e0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(int); virtual void slot9(); virtual void slot10(int);
};
struct FEScreenBase {
 virtual void vfunc_0();
 Manager_ef6e0* manager;
 char pad8[0x40]; Widget_ef6e0* widget;
 char pad4c[0x944]; unsigned primary; unsigned items[4];
 char pad9a4[0x100]; unsigned x; float y; unsigned z; unsigned char enabled; char padab1[3]; unsigned value;
 void FUN_000e4640();
 void vfunc_14();
};
void FEScreenBase::vfunc_14() {
 manager->slot40(primary);
 manager->slot41();
 Manager_ef6e0* saved = manager;
 for(int i=0;i<2;++i) { unsigned item = saved->items[i]; if(item) saved->slot42(item); }
 for(int j=0;j<4;++j) { unsigned item = items[j]; if(item) manager->slot42(item); }
 Settings_ef6e0* settings = manager->slot43();
 settings->enabled = enabled;
 if(enabled) { unsigned savedX = x; settings->y = y; settings->x = savedX; settings->z = z; }
 settings->value = value;
 FUN_000e4640();
 if(widget) { widget->slot8(0); widget->slot10(2); }
}
