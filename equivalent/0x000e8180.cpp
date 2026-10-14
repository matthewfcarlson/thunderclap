// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000e8180 @ 0x000e8180
struct Item { void FUN_000fa0a0(); unsigned int FUN_000fad90(); };
struct Node {
 virtual void v0(); virtual unsigned int v1();
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(unsigned int);
 virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(unsigned int);
};
struct FEThingsBase {
 struct ParseFunctor {
 virtual void invoke();
 FEThingsBase* owner;
 void (FEThingsBase::*callback)(Item*, unsigned int, Node*, Node*);
 unsigned int second;
 Node* third;
 };
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
 virtual bool v34(Item*,Node*,ParseFunctor*);
 virtual void v35(); virtual void v36();
 virtual bool v37(Item*,Node*,Node*);
 void FUN_000e8180(Item*,unsigned int,Node*,Node*);
};
void FEThingsBase::FUN_000e8180(Item* item,unsigned int second,Node* third,Node* fourth) {
 unsigned int kind=fourth->v1();
 if(kind==0x887d4b38) { third->v16(item->FUN_000fad90()); }
 else if(kind==0x16b6f665) { third->v53(item->FUN_000fad90()); }
 else if(!v37(item,third,fourth)) {
 ParseFunctor f;
 f.owner=this;
 f.callback=&FEThingsBase::FUN_000e8180;
 f.second=second;
 f.third=third;
 if(!v34(item,fourth,&f)) item->FUN_000fa0a0();
 }
}
