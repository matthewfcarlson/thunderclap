// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 10/10)
// FUN_000ce750 @ 0x000ce750
struct Item {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void setPosition(float);
 virtual void slot13();
 virtual void setRange(float,float);
 virtual void slot15();
 virtual void setMode(int);
 virtual void slot17();
 virtual void setEnabled(int);
};
struct Collection { char pad[0x24]; Item** begin; Item** end; };
struct Object { char pad[0x248]; Collection* collection; int value; void FUN_000ce750(int); };
void Object::FUN_000ce750(int v) {
 if(v != 0 && value == v) return;
 value = v;
 float first = 0.0f, last = 0.0f;
 int mode = 1, enabled = 0;
 if(v != 0) {
 int n = v * 30;
 first = (float)(n - 29);
 last = (float)n;
 mode = 2; enabled = 1;
 }
 if((unsigned char)(collection->end - collection->begin) == 0) return;
 int i = 0;
 do {
 Item* item = collection->begin[(unsigned char)i];
 item->setRange(first,last);
 item->setPosition(first);
 item->setMode(mode);
 item->setEnabled(enabled);
 ++i;
 } while(i < (unsigned char)(collection->end - collection->begin));
}
