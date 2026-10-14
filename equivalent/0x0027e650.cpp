// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_0027e650 @ 0x0027e650
struct Resource_27e650 {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void SetPosition(float);
 virtual void slot13();
 virtual void SetRange(float, float);
 virtual void slot15();
 virtual void SetMode(int);
 virtual void slot17();
 virtual void Enable(int);
};
struct Controller_27e650 {
 char pad0[0x40];
 int state;
 int secondary;
 char pad48[0x40];
 Resource_27e650* resource;
 unsigned char flag;
 void FUN_0027d780();
 void FUN_0027dca0();
 void FUN_0027e650(Resource_27e650*, float, float);
};
void Controller_27e650::FUN_0027e650(Resource_27e650* incoming, float start, float end) {
 if (resource) {
  if (!incoming) {
   resource->Release();
   resource = 0;
   state = 0;
   secondary = 0;
   FUN_0027d780();
   if (flag == 1) FUN_0027dca0();
   return;
  }
 } else if (!incoming) return;
 incoming->AddRef();
 if (resource) resource->Release();
 resource = incoming;
 state = -1;
 if (start > end) {
  resource->SetRange(end, start);
  resource->SetPosition(start);
  resource->SetMode(3);
  resource->Enable(1);
 } else {
  resource->SetRange(start, end);
  resource->SetPosition(start);
  resource->SetMode(2);
  resource->Enable(1);
 }
}
