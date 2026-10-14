// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 22/22)
// FUN_000e5330 @ 0x000e5330
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void update(); };
struct Link { void FUN_000fb640(void*, void*, unsigned int); };
struct Entry { char prefix[0xb0]; Link* links[12]; char data[4]; };
struct Owner { char pad[0x17f8]; unsigned int index; };
struct Target {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void finishOne(); virtual void finishTwo();
 Owner* owner; char pad0[0x44]; Item* items[128]; char pad1[0x200]; Entry* entries[128]; char pad2[0x42c]; unsigned int mode;
 void run();
};
void Target::run() {
 for (int i=0;i<128;++i) { Item* p=items[i]; if(!p) break; p->update(); }
 if(mode==1 || mode==2) {
  for(int i=0;i<128;++i) {
   Entry* p=entries[i]; if(!p) break;
   unsigned int m=mode;
   if(m) { Link* link=p->links[owner->index+m*4]; if(link) link->FUN_000fb640(p->data,p,(m & 0xffffff00u) | (m==1 ? 1u:0u)); }
  }
 }
 if(mode==2) finishTwo();
 if(mode==1) finishOne();
}