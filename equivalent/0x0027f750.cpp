// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0027f750 @ 0x0027f750
#include "decls/address.h"
struct Gfx {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void draw(unsigned int, unsigned int); virtual void v33(); virtual void v34(); virtual void reset(unsigned int); virtual void v36(); virtual void v37(); virtual void state(unsigned int,unsigned int); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void set(unsigned char); virtual unsigned char get();
};
struct Resource_27f750 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void bind(int); };
struct Data_27f750 { char pad[16]; unsigned int value; };
struct Object { char pad0[20]; Data_27f750* data; char pad1[20]; Resource_27f750* resource; char pad2[36]; unsigned int count; void target(unsigned int,unsigned int); };
void Object::target(unsigned int,unsigned int) {
 unsigned char saved = DAT_0052c2a8->get();
 DAT_0052c2a8->set(0);
 DAT_0052c2a8->state(0,0);
 DAT_0052c2a8->state(1,0);
 DAT_0052c2a8->state(2,0);
 DAT_0052c2a8->state(3,0);
 DAT_0052c2a8->reset(0);
 if(data && resource) {
 resource->bind(0);
 DAT_0052c2a8->state(0,1);
 if(count) DAT_0052c2a8->draw(data->value,count);
 }
 DAT_0052c2a8->set(saved);
}
