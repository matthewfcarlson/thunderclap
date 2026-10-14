// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 16/16)
// FUN_000bb970 @ 0x000bb970
struct Provider_bb970 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual int v44();
};
struct Text_bb970 { void FUN_000f79a0(const unsigned short*, int); };
struct Element_bb970 { char pad[0x18]; Text_bb970 text; char gap[0x57]; int state; };
struct Object { char pad0[4]; Provider_bb970* provider; char pad1[0x984]; Element_bb970* main; Element_bb970* first; Element_bb970* second; void update(const unsigned short*,const unsigned short*,const unsigned short*); };
void Object::update(const unsigned short* a,const unsigned short* b,const unsigned short* c) {
 Text_bb970* text = &main->text;
 int value = provider->v44();
 text->FUN_000f79a0(a,value);
 main->state = ((b && *b) || (c && *c)) ? 1 : 2;
 if (b && first) { text = &first->text; value = provider->v44(); text->FUN_000f79a0(b,value); }
 if (c && second) { text = &second->text; value = provider->v44(); text->FUN_000f79a0(c,value); }
}
