// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_0009bc60 @ 0x0009bc60
struct Resource {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void activate(unsigned); virtual void deactivate(unsigned);
 void FUN_000a08e0(unsigned);
};
struct Part { void FUN_000a91d0(unsigned); };
struct Owner {
 unsigned unknown0; unsigned flags; char pad8[8]; Resource* current; Resource* pending; unsigned char ready; unsigned char done; char pad1a[0xb0-0x1a]; Part* part0; Part* part1; Resource* resource; Part* part2; Part* part3; Part* part4;
 void FUN_000991b0(unsigned,Resource*,Resource*,unsigned,unsigned);
 void FUN_00099050(unsigned); void FUN_0009a400(unsigned); void FUN_00099470(unsigned);
 void FUN_0009bc60(unsigned);
};
void Owner::FUN_0009bc60(unsigned arg) {
 if(flags & 2) { flags &= ~2u; FUN_000991b0(arg,current,pending,0,0); pending=0; }
 if(flags & 4) FUN_00099050(arg);
 if(flags & 8) FUN_0009a400(arg);
 if(flags & 16) FUN_00099470(arg);
 if(part0) part0->FUN_000a91d0(arg);
 if(part1) part1->FUN_000a91d0(arg);
 if(part2) part2->FUN_000a91d0(arg);
 if(part3) part3->FUN_000a91d0(arg);
 if(part4) part4->FUN_000a91d0(arg);
 if(resource) resource->FUN_000a08e0(arg);
 Resource* old=current;
 ready=1;
 if(old) { old->deactivate(arg); current=0; }
 current=resource;
 resource->activate(arg);
 FUN_000991b0(arg,current,resource,1,1);
 done=1;
}
