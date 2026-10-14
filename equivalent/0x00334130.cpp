// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// movie::RenderStrategyBink::vfunc_4 @ 0x00334130
struct Surface_334130 { char pad[0x48]; unsigned value48; unsigned pad4c; unsigned value50; };
struct Provider_334130 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual Surface_334130* slot13(unsigned, unsigned); };
struct Resource_334130 { char pad[0x10]; Provider_334130* provider; };
struct Entry_334130 { Resource_334130* resource; unsigned a,b,c,d; };
struct Output_334130 { unsigned a,b,c,d,e,f,g,h; };
namespace movie { struct RenderStrategyBink {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual unsigned vfunc_4(Output_334130*); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
char pad[0x28]; unsigned count; unsigned index; Entry_334130 entries[1]; unsigned char active;
};
unsigned RenderStrategyBink::vfunc_4(Output_334130* out) {
if(index >= count) return 0;
// The active flag shares storage with the first entry's trailing word.
((unsigned char*)&entries[0].d)[4] = 1;
Surface_334130* s = entries[index].resource->provider->slot13(0,0);
out->a = s->value50; out->b = s->value48; out->c=0; out->d=0;
out->e=entries[index].a; out->f=entries[index].b; out->g=entries[index].c; out->h=entries[index].d;
return count-index;
}
}