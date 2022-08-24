//
//  WTRunningModel.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTRunningModel : NSObject
@property (nonatomic , copy) NSString              * Status;
@property (nonatomic , copy) NSString              * SN;
@property (nonatomic , copy) NSString              * Time;
@property (nonatomic , copy) NSString              * Ppv1;
@property (nonatomic , copy) NSString              * Ppv2;
@property (nonatomic , copy) NSString              * Ppv3;
@property (nonatomic , copy) NSString              * Ppv4;
@property (nonatomic , copy) NSString              * Ppv5;
@property (nonatomic , copy) NSString              * Ppv6;
@property (nonatomic , copy) NSString              * Upv1;
@property (nonatomic , copy) NSString              * Upv2;
@property (nonatomic , copy) NSString              * Upv3;
@property (nonatomic , copy) NSString              * Upv4;
@property (nonatomic , copy) NSString              * Upv5;
@property (nonatomic , copy) NSString              * Upv6;
@property (nonatomic , copy) NSString              * Ua;
@property (nonatomic , copy) NSString              * Ub;
@property (nonatomic , copy) NSString              * Uc;
@property (nonatomic , copy) NSString              * Fac;
@property (nonatomic , copy) NSString              * Ubus;
@property (nonatomic , copy) NSString              * PrealL1;
@property (nonatomic , copy) NSString              * PrealL2;
@property (nonatomic , copy) NSString              * PrealL3;
@property (nonatomic , copy) NSString              * Tinv;
@property (nonatomic , copy) NSString              * PacL1;
@property (nonatomic , copy) NSString              * PacL2;
@property (nonatomic , copy) NSString              * PacL3;
@property (nonatomic , copy) NSString              * InvWorkMode;
@property (nonatomic , copy) NSString              * EpvTotal;
@property (nonatomic , copy) NSString              * Einput;
@property (nonatomic , copy) NSString              * Eoutput;
@property (nonatomic , copy) NSString              * Echarge;
@property (nonatomic , copy) NSString              * PmeterL1;
@property (nonatomic , copy) NSString              * PmeterL2;
@property (nonatomic , copy) NSString              * PmeterL3;
@property (nonatomic , copy) NSString              * PmeterDC;
@property (nonatomic , copy) NSString              * Pbat;
@property (nonatomic , copy) NSString              * SOC;
@property (nonatomic , copy) NSString              * BatV;
@property (nonatomic , copy) NSString              * BatC;
@property (nonatomic , copy) NSString              * FlagBms;
@property (nonatomic , copy) NSString              * BmsWork;
@property (nonatomic , copy) NSString              * Pcharge;
@property (nonatomic , copy) NSString              * Pdischarge;
@property (nonatomic , copy) NSString              * BmsRelay;
@property (nonatomic , copy) NSString              * BmsNum;
@property (nonatomic , copy) NSString              * VcellLow;
@property (nonatomic , copy) NSString              * VcellHigh;
@property (nonatomic , copy) NSString              * TcellLow;
@property (nonatomic , copy) NSString              * TcellHigh;
@property (nonatomic , copy) NSString              * IdTempelover;
@property (nonatomic , copy) NSString              * IdTempEover;
@property (nonatomic , copy) NSString              * IdTempediffe;
@property (nonatomic , copy) NSString              * IdChargcurre;
@property (nonatomic , copy) NSString              * IdDischcurre;
@property (nonatomic , copy) NSString              * IdCellvolover;
@property (nonatomic , copy) NSString              * IdCellvollower;
@property (nonatomic , copy) NSString              * IdSoclower;
@property (nonatomic , copy) NSString              * IdCellvoldiffe;
@property (nonatomic , copy) NSString              * BatC1;
@property (nonatomic , copy) NSString              * BatC2;
@property (nonatomic , copy) NSString              * BatC3;
@property (nonatomic , copy) NSString              * BatC4;
@property (nonatomic , copy) NSString              * BatC5;
@property (nonatomic , copy) NSString              * BatC6;
@property (nonatomic , copy) NSString              * SOC1;
@property (nonatomic , copy) NSString              * SOC2;
@property (nonatomic , copy) NSString              * SOC3;
@property (nonatomic , copy) NSString              * SOC4;
@property (nonatomic , copy) NSString              * SOC5;
@property (nonatomic , copy) NSString              * SOC6;
@property (nonatomic , copy) NSString              * ErrInv;
@property (nonatomic , copy) NSString              * WarInv;
@property (nonatomic , copy) NSString              * ErrEms;
@property (nonatomic , copy) NSString              * ErrBms;
@property (nonatomic , copy) NSString              * ErrMeter;
@property (nonatomic , copy) NSString              * ErrBackupBox;
@property (nonatomic , copy) NSString              * EGridCharge;
@property (nonatomic , copy) NSString              * EDischarge;
@property (nonatomic , copy) NSString              * EmsStatus;
@property (nonatomic , copy) NSString              * InvBatV;
@property (nonatomic , copy) NSString              * BmsShutdown;
@property (nonatomic , copy) NSString              * BmuRelay;
@property (nonatomic , copy) NSString              * BmsHardVer1;
@property (nonatomic , copy) NSString              * BmsHardVer2;
@property (nonatomic , copy) NSString              * BmsHardVer3;
@property (nonatomic , copy) NSString              * DispatchSwitch;
@property (nonatomic , copy) NSString              * Pdispatch;
@property (nonatomic , copy) NSString              * DispatchSoc;
@property (nonatomic , copy) NSString              * DispatchMode;
@property (nonatomic , copy) NSString              * PMeterDCL1;
@property (nonatomic , copy) NSString              * PMeterDCL2;
@property (nonatomic , copy) NSString              * PMeterDCL3;
@property (nonatomic , copy) NSString              * MeterDCUa;
@property (nonatomic , copy) NSString              * MeterDCUb;
@property (nonatomic , copy) NSString              * MeterDCUc;
@property (nonatomic , copy) NSString              * DCI;
@property (nonatomic , copy) NSString              * RCD;
@property (nonatomic , copy) NSString              * PvISO;
@property (nonatomic , copy) NSString              * ChargeBoostCur;
@property (nonatomic , copy) NSString              * InvGV1;
@property (nonatomic , copy) NSString              * InvGV2;
@property (nonatomic , copy) NSString              * InvGV3;
@property (nonatomic , copy) NSString              * InvGF;
@property (nonatomic , copy) NSString              * GCPower;
@property (nonatomic , copy) NSString              * EGCoutput;

@end

NS_ASSUME_NONNULL_END
