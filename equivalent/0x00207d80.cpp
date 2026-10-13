// STATUS: equivalent (tools/equiv.py level 3: 1569 inputs, branch coverage 14/14)
// FUN_00207d80 @ 0x00207d80
struct Entry { char pad[9]; unsigned char flag; };
struct Manager { Entry* FUN_001c7f10(int); };
struct Context { int unused; Manager* manager; };
Context* __cdecl FUN_001c3d90();
struct System {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void refresh();
};
extern System* DAT_0052c2a8;
struct Object {
 char pad[0x9a8]; int count; int first[20]; int second[20]; int entryCount; int entries[41]; unsigned char flag1,flag2; char pad2[6]; int state;
 int FUN_00267f80(); void FUN_00204e40(); void FUN_00207080(int); void FUN_00207580(int,int); void target();
};
void Object::target() {
 state=FUN_00267f80();
 DAT_0052c2a8->refresh();
 if (!FUN_001c3d90()->manager) {
 entryCount=0; count=0; flag1=0; flag2=0; FUN_00204e40(); state=0; return;
 }
 for(int i=0;i<entryCount;++i) {
 int id=entries[i];
 FUN_001c3d90()->manager->FUN_001c7f10(id)->flag=0;
 }
 entryCount=0;
 FUN_00204e40();
 for(int j=0;j<count;++j) {
 if(first[j]>0) FUN_00207080(first[j]);
 if(second[j]>0) FUN_00207580(second[j],1);
 }
 count=0; state=0; flag1=0; flag2=0;
}
