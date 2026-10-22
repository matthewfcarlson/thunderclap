// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000d82d0 @ 0x000d82d0
struct Item_d82d0 { char data[0x24]; void FUN_000f7930(); };
struct Entry_d82d0 { Item_d82d0 item; char pad[12]; unsigned char active; char pad2[7]; unsigned char flag; char pad3[3]; };
struct CGlowDisplayEffect_d82d0 { char data[0x1c]; void FUN_000dee10(); };
struct CDropShadowDisplayEffect_d82d0 { char data[0x14]; void FUN_000dee40(); };
struct Record_d82d0 { int a,b,c,d; };
struct FUN_000e9240 {
 virtual void slot0();
 char pad0[0x14c]; int owner;
 char pad1[0x78]; int index; int value; int other; unsigned char flag1,flag2; char pad2[0x46];
 FUN_000e9240(int);
};
struct FEMemCardControl : FUN_000e9240 {
 virtual void slot0();
 Entry_d82d0 entries[5];
 char gap[0x10];
 Item_d82d0 item1; unsigned char flag380; char pad380[3];
 Item_d82d0 item2; unsigned char enabled; char pad3a8[3]; int count; unsigned char flag3b0; char pad3b0[3];
 CGlowDisplayEffect_d82d0 stateA; CDropShadowDisplayEffect_d82d0 stateB;
 int stateValue; unsigned char f8,f9,fa,fb,fc; char pad3ed[3]; int stateOther;
 Item_d82d0 item3; int mask; char pad41c[12]; FEMemCardControl* self; char pad42c[4]; Record_d82d0 records[2];
 FEMemCardControl(int first,int second);
};
FEMemCardControl::FEMemCardControl(int first,int second) : FUN_000e9240(first) {
 for(int i=0;i<5;++i) { entries[i].item.FUN_000f7930(); entries[i].active=0; entries[i].flag=0; }
 item1.FUN_000f7930(); flag380=0;
 item2.FUN_000f7930(); stateA.FUN_000dee10(); stateB.FUN_000dee40(); item3.FUN_000f7930();
 records[0].a=0; records[0].b=0; records[0].c=0; records[0].d=-1;
 records[1].a=0; records[1].b=0; records[1].c=0; records[1].d=-1;
 value=0; flag1=0; flag2=0; other=0; count=0; flag3b0=0; stateValue=0; f8=0; f9=0; fc=0; stateOther=0; owner=second; enabled=1; index=0; fb=0; fa=0; mask=31; self=this;
}
