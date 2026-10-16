// STATUS: equivalent (tools/equiv.py level 3: 2977 inputs, branch coverage 6/6)
// FUN_001c2210 @ 0x001c2210
#include "decls/address.h"
struct Gfx {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void enable(int);
};
struct Material_1c2210 { char pad[0x20]; unsigned color; float scale; unsigned zero; unsigned mode; unsigned otherColor; float low, high; char pad2[0x80]; unsigned char enabled; int FUN_00293ef0(); };
struct Helper_1c2210 { void FUN_002a1340(unsigned); };
struct Object { unsigned count; Material_1c2210* material; char pad[0xd1]; unsigned char enabled; char pad2[2]; unsigned color; char pad3[4]; float a,b; unsigned value; Helper_1c2210* helper; int run(); };
int Object::run() {
 ++count;
 DAT_0052c2a8->enable(1);
 float lo = a < b ? a : b;
 float hi = a < b ? b : a;
 material->otherColor = color;
 material->low = lo;
 material->high = hi;
 material->enabled = enabled;
 material->color = enabled ? color : 0xff000000;
 helper->FUN_002a1340(value);
 material->scale = 1.0f;
 material->zero = 0;
 material->mode = 7;
 return material->FUN_00293ef0();
}