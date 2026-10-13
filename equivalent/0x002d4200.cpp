// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d4200 @ 0x002d4200
struct Matrix { char data[64]; void FUN_0022b980(); };
struct State {
 unsigned int field0; char pad4[4]; Matrix first; Matrix second;
 float f88,f8c; unsigned char enabled; char pad91[3];
 float f94,f98,f9c,fa0,fa4,fa8,fac,fb0;
 unsigned char flagb4; char padb5[3];
 float fb8,fbc,fc0,fc4,fc8,fcc,fd0,fd4,fd8,fdc,fe0,fe4,fe8,fec,ff0,ff4,ff8,ffc,f100,f104,f108;
 int index; unsigned char flag110,flag111;
 State* FUN_002d4200();
};
State* State::FUN_002d4200() {
 fb0=fc0=fc4=fcc=fd0=fd4=fd8=fec=ff0=ff8=f100=f108=1.0f;
 field0=0; f88=0.0f; f8c=0.0f; enabled=1;
 f94=f98=f9c=fa0=fa4=fa8=0.0f;
 fac=10.0f; flagb4=0; fb8=30.0f;
 fbc=fc8=fdc=fe0=fe4=fe8=ff4=ffc=f104=0.0f;
 index=-1; flag110=0; flag111=0;
 first.FUN_0022b980(); second.FUN_0022b980();
 return this;
}