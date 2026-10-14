// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00083c30 @ 0x00083c30
typedef unsigned int Word_83c30;
struct Handle_83c30 { Word_83c30 words[2]; void FUN_0027b040(Word_83c30); };
struct FUN_0027b070 { virtual void slot0(); FUN_0027b070(); };
struct Triple_83c30 { Word_83c30 x,y,z; };
struct CVehicle : FUN_0027b070 {
 virtual void slot0();
 Word_83c30 unknown4;
 Handle_83c30 handle;
 Word_83c30 state;
 unsigned char flag; char pad15[3];
 Word_83c30 value18,value1c;
 Word_83c30 state20,state24,state28;
 unsigned char flag2c,flag2d; char pad2e[2];
 Word_83c30 state30;
 Word_83c30 value34,value38,value3c,value40;
 Triple_83c30 position,rotation;
 Word_83c30 value5c;
 Triple_83c30 originalPosition;
 char pad6c[0x4c];
 Word_83c30 stateb8,statebc;
 CVehicle(Word_83c30 a1,Word_83c30 a2,Word_83c30 a3,Word_83c30 a4,Word_83c30 a5,Word_83c30 a6,Word_83c30 a7,Word_83c30 a8,Word_83c30 a9,Word_83c30 a10,Word_83c30 a11,Word_83c30 a12,Word_83c30 a13);
};
CVehicle::CVehicle(Word_83c30 a1,Word_83c30 a2,Word_83c30 a3,Word_83c30 a4,Word_83c30 a5,Word_83c30 a6,Word_83c30 a7,Word_83c30 a8,Word_83c30 a9,Word_83c30 a10,Word_83c30 a11,Word_83c30 a12,Word_83c30 a13) {
 value18=a12; value1c=a12;
 value34=a2; value38=a3; value3c=a4; value40=a5;
 position.x=a6; position.y=a7; position.z=a8;
 rotation.x=a9; rotation.y=a10; rotation.z=a11;
 value5c=a13;
 originalPosition.x=a6; originalPosition.y=a7; originalPosition.z=a8;
 state=0; flag=0; state20=0; state24=0; state28=0; flag2c=0; flag2d=0; state30=0; stateb8=0; statebc=0;
 handle.FUN_0027b040(a1);
}
