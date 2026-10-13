// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_00283900 @ 0x00283900
struct Resource {
 virtual void acquire();
 virtual void release();
 Resource* FUN_00280120();
 Resource* FUN_00280690(unsigned context);
 Resource* FUN_002821d0();
 Resource* FUN_00283730();
};
extern void* __cdecl FUN_00263ea0(unsigned size);
struct Manager {
 unsigned state;
 unsigned owner;
 unsigned enabled;
 Resource* first;
 Resource* second;
 Resource* third;
 Resource* fourth;
 Manager* FUN_00283900(unsigned ownerValue, unsigned context);
};
extern Manager* DAT_0052c29c;
Manager* Manager::FUN_00283900(unsigned ownerValue, unsigned context) {
 state=0; owner=ownerValue; enabled=1; first=0; second=0; third=0; fourth=0;
 DAT_0052c29c=this;
 Resource* storage=(Resource*)FUN_00263ea0(0x2598);
 Resource* value=storage ? storage->FUN_00280120() : 0;
 if(value) value->acquire();
 if(first) first->release();
 first=value;
 storage=(Resource*)FUN_00263ea0(0xb10);
 value=storage ? storage->FUN_00280690(context) : 0;
 if(value) value->acquire();
 if(second) second->release();
 second=value;
 storage=(Resource*)FUN_00263ea0(0x58);
 value=storage ? storage->FUN_002821d0() : 0;
 if(value) value->acquire();
 if(third) third->release();
 third=value;
 storage=(Resource*)FUN_00263ea0(0x60);
 value=storage ? storage->FUN_00283730() : 0;
 if(value) value->acquire();
 if(fourth) fourth->release();
 fourth=value;
 return this;
}