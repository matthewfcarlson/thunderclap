// STATUS: equivalent (tools/equiv.py level 3: 2181 inputs, branch coverage 22/22)
// FUN_001c0250 @ 0x001c0250
struct sSubtitleManagerCallback { virtual void slot0(); unsigned value; };
extern "C" void* __cdecl memcpy(void*,const void*,unsigned);
void __cdecl FUN_0008d330(void*);
void __cdecl FUN_0008d340(void*);
struct Item { virtual void destroy(unsigned); unsigned pad4; unsigned field8; unsigned char flagC; char padD[3]; unsigned field10, field14; char pad18[4]; unsigned short field1C; };
struct Resource { void FUN_000f6f60(); };
struct Last { virtual void slot0(); virtual void release(); };
struct Manager {
 float value; unsigned field4; void* field8; char padC; unsigned char flagD; char padE[18]; unsigned type; unsigned char flag24; char pad25[3]; void** entries; Item* item; sSubtitleManagerCallback* callback; Resource* resource34; Resource* resource38; void* buffer; unsigned count; char pad44[12]; unsigned field50; char pad54; unsigned char flag55; char pad56[2]; Last* last;
 void cleanup();
};
void Manager::cleanup() {
 field4=0; value=-1.0f; flagD=0; flag24=0; flag55=0;
 if(type==2) item->flagC=0;
 field50=0;
 Item* p=item; p->flagC=0; p->field10=0; p->field8=0; p->field14=0; p->field1C=0;
 if(callback) { sSubtitleManagerCallback* c=callback; sSubtitleManagerCallback reset; reset.value=0; memcpy(c,&reset,sizeof(reset)); FUN_0008d330(c); callback=0; }
 if(item) { item->destroy(1); item=0; }
 void* b=buffer; count=0; if(b) { FUN_0008d340(b); buffer=0; }
 Resource* r=resource38; if(r) { r->FUN_000f6f60(); FUN_0008d330(r); resource38=0; }
 r=resource34; if(r) { r->FUN_000f6f60(); FUN_0008d330(r); resource34=0; }
 if(field8) { FUN_0008d340(field8); field8=0; }
 for(int i=0;i<10;++i) { if(entries[i]) { FUN_0008d340(entries[i]); entries[i]=0; } }
 if(entries) { FUN_0008d340(entries); entries=0; }
 if(last) { last->release(); last=0; }
}
