// STATUS: equivalent (tools/equiv.py level 3: 356 inputs, branch coverage 12/12)
// FUN_002ff0c0 @ 0x002ff0c0
struct Source_2ff0c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void activate(); char pad[0x15]; unsigned char active; };
struct Destination_2ff0c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int type(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void attach(Source_2ff0c0*,int); };
struct SourceEntry_2ff0c0 { char pad[0x20]; Source_2ff0c0* source; };
struct DestEntry_2ff0c0 { char pad[0x10]; Destination_2ff0c0* destination; };
struct Group_2ff0c0 { char pad[0x10]; SourceEntry_2ff0c0** sources; SourceEntry_2ff0c0** sourcesEnd; char pad2[8]; DestEntry_2ff0c0** destinations; DestEntry_2ff0c0** destinationsEnd; char pad3[0x44]; };
struct Manager_2ff0c0 { Group_2ff0c0* groups; char pad[0x54]; int state; void target(int index); };
void Manager_2ff0c0::target(int index) {
 unsigned int i=0;
 while(i < (unsigned int)(groups[index].sourcesEnd-groups[index].sources)) {
  Source_2ff0c0* source=groups[index].sources[i]->source;
  if(!source->active) source->activate();
  unsigned int j=0;
  while(j < (unsigned int)(groups[index].destinationsEnd-groups[index].destinations)) {
   state=0;
   Destination_2ff0c0* destination=groups[index].destinations[j]->destination;
   if(destination->type()==4) destination->attach(source,1);
   ++j;
  }
  ++i;
 }
}