
#ifndef _PP_PROJ_H_
#define _PP_PROJ_H_
//***********************************************************************************
// C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// global Mypvar - access with "Mypvar"
// global Myparray(32) - access with "Myparray(i)"
// csglobal Myqvar - access with "Myqvar(i)" where "i" is Coord #
// csglobal Myqarray(16) - access with "Myqvar(i,j)" where "j" is index
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
// Example
// global Mypvar
// csglobal Myqvar
// "SetGlobalVar(Myqvar, data)" will give a compile error because its a csglobal var.
// "SetCSGlobalVar(Mypvar, data)" will give a compile error because its a global var.
//************************************************************************************

#ifdef _PPScriptMode_
enum globalP {_globalP_=-1};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};

enum ptrM {_ptrM_=-1
,ZJP_READY=8265
,ZJP_ALM=8266
,ZJP_TIM=8267
,JZDJ_READY=8268
,JZDJ_ALM=8269
,JZDJ_TIM=8270
,YZ_Z_ALM=8271
,YZ_Z_READY=8272
,ZJ_Z_ALM=8273
,ZJ_Z_READY=8274
,TP_Z_ALM=8275
,TP_Z_READY=8276
,DS_READY=8277
,DS_ALM=8278
,DS_INPOS=8279
,YZXJ_Z_READY=8280
,YZXJ_Z_INPOS=8281
,YZXJ_Z_ALM=8282
,TPXJ_Z_READY=8283
,TPXJ_Z_INPOS=8284
,TPXJ_Z_ALM=8285
,ZJP_FREE=8286
,ZJP_RESET=8287
,JZDJ_FREE=8288
,JZDJ_RESET=8289
,YZ_Z_STO=8290
,YZ_Z_CLEAR=8291
,ZJ_Z_STO=8292
,ZJ_Z_CLEAR=8293
,TP_Z_STO=8294
,TP_Z_CLEAR=8295
,DS_FREE=8296
,DS_RESET=8297
,YZXJ_Z_FREE=8298
,YZXJ_Z_RESET=8299
,TPXJ_Z_FREE=8300
,TPXJ_Z_RESET=8301};
enum ptrMarray {_ptrMarray_=-1
,MotorStatus0=8192
,CoordStatus0=8223
,MotorDesPos=8244
,AD=8302};
#define	Mtr1MaxSpeed	pshm->P[8192]
#define	Enc1Res	pshm->P[8193]
#define	Mtr1Gear	pshm->P[8194]
#define	Mtr2MaxSpeed	pshm->P[8195]
#define	Enc2Res	pshm->P[8196]
#define	Mtr2Gear	pshm->P[8197]
#define	Mtr3MaxSpeed	pshm->P[8198]
#define	Enc3Res	pshm->P[8199]
#define	Mtr3Gear	pshm->P[8200]
#define	Mtr4MaxSpeed	pshm->P[8201]
#define	Enc4Res	pshm->P[8202]
#define	Mtr4Gear	pshm->P[8203]
#define	Mtr5MaxSpeed	pshm->P[8204]
#define	Enc5Res	pshm->P[8205]
#define	Mtr5Gear	pshm->P[8206]
#define	Mtr6MaxSpeed	pshm->P[8207]
#define	Enc6Res	pshm->P[8208]
#define	Mtr6Gear	pshm->P[8209]
#define	Mtr7MaxSpeed	pshm->P[8210]
#define	Enc7Res	pshm->P[8211]
#define	Mtr7Gear	pshm->P[8212]
#define	Mtr8MaxSpeed	pshm->P[8213]
#define	Enc8Res	pshm->P[8214]
#define	Mtr8Gear	pshm->P[8215]
#define	Mtr9MaxSpeed	pshm->P[8216]
#define	Enc9Res	pshm->P[8217]
#define	Mtr9Gear	pshm->P[8218]
#define	Mtr10MaxSpeed	pshm->P[8219]
#define	Enc10Res	pshm->P[8220]
#define	Mtr10Gear	pshm->P[8221]
#define	Mtr11MaxSpeed	pshm->P[8222]
#define	Enc11Res	pshm->P[8223]
#define	Mtr11Gear	pshm->P[8224]
#define	Mtr12MaxSpeed	pshm->P[8225]
#define	Enc12Res	pshm->P[8226]
#define	Mtr12Gear	pshm->P[8227]
#define	Mtr13MaxSpeed	pshm->P[8228]
#define	Enc13Res	pshm->P[8229]
#define	Mtr13Gear	pshm->P[8230]
#define	Mtr14MaxSpeed	pshm->P[8231]
#define	Enc14Res	pshm->P[8232]
#define	Mtr14Gear	pshm->P[8233]
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _PPScriptMode_
#else
#ifdef _EnumMode_
enum globalP {_globalP_=-1
,Mtr1MaxSpeed=8192
,Enc1Res=8193
,Mtr1Gear=8194
,Mtr2MaxSpeed=8195
,Enc2Res=8196
,Mtr2Gear=8197
,Mtr3MaxSpeed=8198
,Enc3Res=8199
,Mtr3Gear=8200
,Mtr4MaxSpeed=8201
,Enc4Res=8202
,Mtr4Gear=8203
,Mtr5MaxSpeed=8204
,Enc5Res=8205
,Mtr5Gear=8206
,Mtr6MaxSpeed=8207
,Enc6Res=8208
,Mtr6Gear=8209
,Mtr7MaxSpeed=8210
,Enc7Res=8211
,Mtr7Gear=8212
,Mtr8MaxSpeed=8213
,Enc8Res=8214
,Mtr8Gear=8215
,Mtr9MaxSpeed=8216
,Enc9Res=8217
,Mtr9Gear=8218
,Mtr10MaxSpeed=8219
,Enc10Res=8220
,Mtr10Gear=8221
,Mtr11MaxSpeed=8222
,Enc11Res=8223
,Mtr11Gear=8224
,Mtr12MaxSpeed=8225
,Enc12Res=8226
,Mtr12Gear=8227
,Mtr13MaxSpeed=8228
,Enc13Res=8229
,Mtr13Gear=8230
,Mtr14MaxSpeed=8231
,Enc14Res=8232
,Mtr14Gear=8233};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};
enum ptrM {_ptrM_=-1
,ZJP_READY=8265
,ZJP_ALM=8266
,ZJP_TIM=8267
,JZDJ_READY=8268
,JZDJ_ALM=8269
,JZDJ_TIM=8270
,YZ_Z_ALM=8271
,YZ_Z_READY=8272
,ZJ_Z_ALM=8273
,ZJ_Z_READY=8274
,TP_Z_ALM=8275
,TP_Z_READY=8276
,DS_READY=8277
,DS_ALM=8278
,DS_INPOS=8279
,YZXJ_Z_READY=8280
,YZXJ_Z_INPOS=8281
,YZXJ_Z_ALM=8282
,TPXJ_Z_READY=8283
,TPXJ_Z_INPOS=8284
,TPXJ_Z_ALM=8285
,ZJP_FREE=8286
,ZJP_RESET=8287
,JZDJ_FREE=8288
,JZDJ_RESET=8289
,YZ_Z_STO=8290
,YZ_Z_CLEAR=8291
,ZJ_Z_STO=8292
,ZJ_Z_CLEAR=8293
,TP_Z_STO=8294
,TP_Z_CLEAR=8295
,DS_FREE=8296
,DS_RESET=8297
,YZXJ_Z_FREE=8298
,YZXJ_Z_RESET=8299
,TPXJ_Z_FREE=8300
,TPXJ_Z_RESET=8301};
enum ptrMarray {_ptrMarray_=-1
,MotorStatus0=8192
,CoordStatus0=8223
,MotorDesPos=8244
,AD=8302};
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _EnumMode_
#else
// ***** Standard default mode *****
#define MotorStatus0 8192
#define CoordStatus0 8223
#define MotorDesPos 8244
#define Mtr1MaxSpeed 8192
#define Enc1Res 8193
#define Mtr1Gear 8194
#define Mtr2MaxSpeed 8195
#define Enc2Res 8196
#define Mtr2Gear 8197
#define Mtr3MaxSpeed 8198
#define Enc3Res 8199
#define Mtr3Gear 8200
#define Mtr4MaxSpeed 8201
#define Enc4Res 8202
#define Mtr4Gear 8203
#define Mtr5MaxSpeed 8204
#define Enc5Res 8205
#define Mtr5Gear 8206
#define Mtr6MaxSpeed 8207
#define Enc6Res 8208
#define Mtr6Gear 8209
#define Mtr7MaxSpeed 8210
#define Enc7Res 8211
#define Mtr7Gear 8212
#define Mtr8MaxSpeed 8213
#define Enc8Res 8214
#define Mtr8Gear 8215
#define Mtr9MaxSpeed 8216
#define Enc9Res 8217
#define Mtr9Gear 8218
#define Mtr10MaxSpeed 8219
#define Enc10Res 8220
#define Mtr10Gear 8221
#define Mtr11MaxSpeed 8222
#define Enc11Res 8223
#define Mtr11Gear 8224
#define Mtr12MaxSpeed 8225
#define Enc12Res 8226
#define Mtr12Gear 8227
#define Mtr13MaxSpeed 8228
#define Enc13Res 8229
#define Mtr13Gear 8230
#define Mtr14MaxSpeed 8231
#define Enc14Res 8232
#define Mtr14Gear 8233
#define ZJP_READY 8265
#define ZJP_ALM 8266
#define ZJP_TIM 8267
#define JZDJ_READY 8268
#define JZDJ_ALM 8269
#define JZDJ_TIM 8270
#define YZ_Z_ALM 8271
#define YZ_Z_READY 8272
#define ZJ_Z_ALM 8273
#define ZJ_Z_READY 8274
#define TP_Z_ALM 8275
#define TP_Z_READY 8276
#define DS_READY 8277
#define DS_ALM 8278
#define DS_INPOS 8279
#define YZXJ_Z_READY 8280
#define YZXJ_Z_INPOS 8281
#define YZXJ_Z_ALM 8282
#define TPXJ_Z_READY 8283
#define TPXJ_Z_INPOS 8284
#define TPXJ_Z_ALM 8285
#define ZJP_FREE 8286
#define ZJP_RESET 8287
#define JZDJ_FREE 8288
#define JZDJ_RESET 8289
#define YZ_Z_STO 8290
#define YZ_Z_CLEAR 8291
#define ZJ_Z_STO 8292
#define ZJ_Z_CLEAR 8293
#define TP_Z_STO 8294
#define TP_Z_CLEAR 8295
#define DS_FREE 8296
#define DS_RESET 8297
#define YZXJ_Z_FREE 8298
#define YZXJ_Z_RESET 8299
#define TPXJ_Z_FREE 8300
#define TPXJ_Z_RESET 8301
#define AD 8302
#endif
#endif
#endif //_PP_PROJ_H_
