// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00083c30 @ 0x00083c30
typedef unsigned int Word;
struct Handle { Word words[2]; void FUN_0027b040(Word); };
struct FUN_0027b070 { virtual void slot0(); FUN_0027b070(); };
struct Triple { Word x,y,z; };
struct CVehicle : FUN_0027b070 {
 virtual void slot0();
 Word unknown4;
 Handle handle;
 Word state;
 unsigned char flag; char pad15[3];
 Word value18,value1c;
 Word state20,state24,state28;
 unsigned char flag2c,flag2d; char pad2e[2];
 Word state30;
 Word value34,value38,value3c,value40;
 Triple position,rotation;
 Word value5c;
 Triple originalPosition;
 char pad6c[0x4c];
 Word stateb8,statebc;
 CVehicle(Word a1,Word a2,Word a3,Word a4,Word a5,Word a6,Word a7,Word a8,Word a9,Word a10,Word a11,Word a12,Word a13);
};
CVehicle::CVehicle(Word a1,Word a2,Word a3,Word a4,Word a5,Word a6,Word a7,Word a8,Word a9,Word a10,Word a11,Word a12,Word a13) {
 value18=a12; value1c=a12;
 value34=a2; value38=a3; value3c=a4; value40=a5;
 position.x=a6; position.y=a7; position.z=a8;
 rotation.x=a9; rotation.y=a10; rotation.z=a11;
 value5c=a13;
 originalPosition.x=a6; originalPosition.y=a7; originalPosition.z=a8;
 state=0; flag=0; state20=0; state24=0; state28=0; flag2c=0; flag2d=0; state30=0; stateb8=0; statebc=0;
 handle.FUN_0027b040(a1);
}
