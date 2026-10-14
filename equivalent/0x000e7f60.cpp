// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000e7f60 @ 0x000e7f60
struct Reader { float FUN_000fad30(); void FUN_000fa0a0(); };
struct Tag_e7f60 { virtual void slot0(); virtual int type(); };
struct Values_e7f60 { float a,b,x,y,z,w; };
struct FEThingsBase {
 struct ParseFunctor;
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual bool parse(Reader*,Tag_e7f60*,ParseFunctor*);
 void FUN_000e7f60(Reader*,void*,Values_e7f60*,Tag_e7f60*);
 struct ParseFunctor {
 virtual void invoke();
 FEThingsBase* owner;
 void (FEThingsBase::*callback)(Reader*,void*,Values_e7f60*,Tag_e7f60*);
 int adjustment;
 Values_e7f60* output;
 };
};
void FEThingsBase::FUN_000e7f60(Reader* reader,void*,Values_e7f60* output,Tag_e7f60* tag) {
 int id=tag->type();
 if(id==(int)0xba2c5954) output->w=reader->FUN_000fad30();
 else if(id==(int)0x946d8562) { float x=reader->FUN_000fad30(); float y=reader->FUN_000fad30(); float z=reader->FUN_000fad30(); output->z=z; output->x=x; output->y=y; }
 else if(id==(int)0xca6fda24) output->b=reader->FUN_000fad30();
 else if(id==0x61e45775) output->a=reader->FUN_000fad30();
 else { ParseFunctor f; f.owner=this; f.callback=&FEThingsBase::FUN_000e7f60; f.adjustment=0; f.output=output; if(!parse(reader,tag,&f)) reader->FUN_000fa0a0(); }
}
