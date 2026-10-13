// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000f1570 @ 0x000f1570
struct Controller { void FUN_000f8b00(float); };
struct Interface { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void slot48(int); };
struct Link { char pad[4]; Interface* iface; };
struct Owner { char pad[8]; Link* link; };
struct Object { char pad0[0x14]; Owner* owner; char pad1[0x138]; float value; int flag; char pad2[4]; float lower; float upper; char pad3[4]; int mode; float rate; char pad4[0x10]; Controller* controller; void FUN_000e9e60(); void update(); };
void Object::update() {
 if (!mode) { if (rate == 0.0f) value += 1.0f; else value += rate; } else flag = 1;
 float result;
 if (value >= lower && value <= upper) result = value;
 else if (value > upper) result = upper;
 else result = lower;
 value = result;
 if (controller) controller->FUN_000f8b00(result);
 owner->link->iface->slot48(3);
 FUN_000e9e60();
}
