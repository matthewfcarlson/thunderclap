// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0027e780 @ 0x0027e780
struct Input { char pad0[12]; float x,y,z; char pad1[32]; unsigned a,b; char pad2[12]; int mode; };
struct Matrix { char data[64]; void FUN_0022b980(); void FUN_0022be40(Input*); void FUN_0022bc20(float,float,float); void FUN_0022ca90(Matrix*,Matrix*); };
struct Bones { char pad[28]; Matrix* matrices; unsigned FUN_002843a0(unsigned,unsigned); };
struct Provider { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual Bones* v11(); };
struct Output { void FUN_0027dde0(Matrix*); };
struct Object { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Matrix* v15(); char pad[152]; Provider* provider; void target(Output*,Input*); };
void Object::target(Output* output,Input* input) { Bones* bones=provider->v11(); Matrix local,result; switch(input->mode) { case 2: result.FUN_0022b980(); result.FUN_0022be40(input); result.FUN_0022bc20(input->x,input->y,input->z); break; case 0: case 1: { int mode=input->mode; local.FUN_0022b980(); local.FUN_0022be40(input); local.FUN_0022bc20(input->x,input->y,input->z); Matrix* parent; if(mode==0) { unsigned index=bones->FUN_002843a0(input->a,input->b); if(index!=65535) parent=&bones->matrices[index]; else parent=v15(); } else parent=v15(); result.FUN_0022ca90(&local,parent); break; } } output->FUN_0027dde0(&result); }
