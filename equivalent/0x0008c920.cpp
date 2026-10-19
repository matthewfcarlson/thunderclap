// STATUS: equivalent (tools/equiv.py level 3: 19964 inputs, branch coverage 15/16, incomplete)
// FUN_0008c920 @ 0x0008c920
// cl-flags: /GS
struct Object {
 virtual void v0(); virtual void release();
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
 virtual void getState(int*);
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
 virtual int value(); virtual void update();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual void query(Object**, char*, int,int,int,int,int);
};
struct State_8c920 { Object* object; char pad[0x58]; int state; char pad2[0x54]; int values[5]; };
struct Manager_8c920 { char pad[8]; State_8c920* data; int FUN_0008c590(int, unsigned, int*); void target(); };
void Manager_8c920::target() {
 struct Workspace { Object* item; int status; char buffer[260];  } work;
 Object* root = data->object;
 if(root) {
 root->getState(&data->state);
 root->update();
 if(data->state == 0) {
 for(unsigned i=0;i<5;++i) {
 work.item=0;
 data->values[i]=1;
 int result=FUN_0008c590(0,i,&work.status);
 if(result) data->values[i]=result;
 else {
 if(work.status==2) data->values[i]=1;
 if(work.status==3) {
 root->query(&work.item,work.buffer,0,0,0,0,1);
 if(work.item) {
 data->values[i]=work.item->value();
 work.item->update();
 if(work.item) work.item->release();
 }
 }
 }
 }
 }
 }
}
