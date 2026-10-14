// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 20/20)
// FUN_00222f40 @ 0x00222f40
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
struct Effect_222f40 {
 virtual void slot0();
 virtual void release();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void update(float);
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual bool finished();
};
struct Entry_222f40 {
 Effect_222f40* effect;
 float delay;
 unsigned char flag;
 char padding[19];
 float fadeIn;
 float fadeOut;
 float weight;
};
struct Manager_222f40 {
 char padding[0x68];
 unsigned int count;
 Entry_222f40 entries[1];
 void FUN_00222f40(float dt);
};
void Manager_222f40::FUN_00222f40(float dt) {
 unsigned int i=0;
 while(i<count) {
  Entry_222f40& e=entries[i];
  Effect_222f40* effect=e.effect;
  if ((e.delay<0.0f && !e.flag) || effect->finished()) {
   if(e.fadeOut<=0.0f) e.weight=0.0f;
   else e.weight=e.weight-dt/e.fadeOut;
   if(e.weight<=0.0f) {
    effect->release();
    --count;
    memmove(&e,&entries[i+1],(count-i)*sizeof(Entry_222f40));
    continue;
   }
  } else {
   if(!e.flag) e.delay-=dt;
   if(e.fadeIn<=0.0f) e.weight=1.0f;
   else {
    double value=(double)dt/e.fadeIn+e.weight;
    e.weight=(float)value;
    if(value>1.0) e.weight=1.0f;
   }
  }
  effect->update(dt);
  ++i;
 }
}
