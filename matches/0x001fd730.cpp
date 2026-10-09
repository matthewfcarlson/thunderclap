class Item { public: virtual void A(); virtual void Release(); };
class Part { public: void Run(); };
class Obj { public: char p0[8]; int f8; Item* items[128]; int f20c; char p210[0x24]; Part* parts; void Clear(); };
void Obj::Clear() {
 int i;
 for (i=0;i<128;i++) { if (items[i]) { items[i]->Release(); items[i]=0; } }
 f8=0; f20c=0;
 for (i=0;i<0x6380;i+=0xc70) ((Part*)((char*)parts+i))->Run();
}
