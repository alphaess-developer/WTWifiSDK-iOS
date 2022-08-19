//
//  WTSystemModel.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTSystemModel : NSObject

@property (nonatomic , copy) NSString              * Status;
@property (nonatomic , copy) NSString              * SN;
@property (nonatomic , copy) NSString              * Time;
@property (nonatomic , copy) NSString              * Address;
@property (nonatomic , copy) NSString              * ZipCode;
@property (nonatomic , copy) NSString              * Country;
@property (nonatomic , copy) NSString              * PhoneNumber;
@property (nonatomic , copy) NSString              * License;
@property (nonatomic , copy) NSString              * Popv;
@property (nonatomic , copy) NSString              * Minv;
@property (nonatomic , copy) NSString              * Poinv;
@property (nonatomic , copy) NSString              * Cobat;
@property (nonatomic , copy) NSString              * Mbat;
@property (nonatomic , copy) NSString              * Uscapacity;
@property (nonatomic , copy) NSString              * InstallMeterOption;
@property (nonatomic , copy) NSString              * Meter_CT_Select;
@property (nonatomic , copy) NSString              * Mmeter;
@property (nonatomic , copy) NSString              * PVMeterMode;
@property (nonatomic , copy) NSString              * CTRate;
@property (nonatomic , copy) NSString              * PVMeterCTRate;
@property (nonatomic , copy) NSString              * GridMeterCTE;
@property (nonatomic , copy) NSString              * PVMeterCTE;
@property (nonatomic , copy) NSString              * BatterySN1;
@property (nonatomic , copy) NSString              * BatterySN2;
@property (nonatomic , copy) NSString              * BatterySN3;
@property (nonatomic , copy) NSString              * BatterySN4;
@property (nonatomic , copy) NSString              * BatterySN5;
@property (nonatomic , copy) NSString              * BatterySN6;
@property (nonatomic , copy) NSString              * BMSVersion1;
@property (nonatomic , copy) NSString              * BMSVersion2;
@property (nonatomic , copy) NSString              * BMSVersion3;
@property (nonatomic , copy) NSString              * BMSVersion4;
@property (nonatomic , copy) NSString              * BMSVersion5;
@property (nonatomic , copy) NSString              * BMSVersion6;
@property (nonatomic , copy) NSString              * BMSPlatform1;
@property (nonatomic , copy) NSString              * BMSPlatform2;
@property (nonatomic , copy) NSString              * BMSPlatform3;
@property (nonatomic , copy) NSString              * BMSPlatform4;
@property (nonatomic , copy) NSString              * BMSPlatform5;
@property (nonatomic , copy) NSString              * BMSPlatform6;
@property (nonatomic , copy) NSString              * BMSVersion;
@property (nonatomic , copy) NSString              * EMSVersion;
@property (nonatomic , copy) NSString              * FirmwareVersion;
@property (nonatomic , copy) NSString              * InvVersion;
@property (nonatomic , copy) NSString              * SlaveVersion;
@property (nonatomic , copy) NSString              * InvHWVersion;
@property (nonatomic , copy) NSString              * InvSN;
@property (nonatomic , copy) NSString              * ACDC;
@property (nonatomic , copy) NSString              * Generator;
@property (nonatomic , copy) NSString              * BackUpBox;
@property (nonatomic , copy) NSString              * Fan;
@property (nonatomic , copy) NSString              * GridCharge;
@property (nonatomic , copy) NSString              * CtrDis;
@property (nonatomic , copy) NSString              * TimeChaFM1;
@property (nonatomic , copy) NSString              * TimeChaEM1;
@property (nonatomic , copy) NSString              * TimeChaFM2;
@property (nonatomic , copy) NSString              * TimeChaEM2;
@property (nonatomic , copy) NSString              * TimeDisFM1;
@property (nonatomic , copy) NSString              * TimeDisEM1;
@property (nonatomic , copy) NSString              * TimeDisFM2;
@property (nonatomic , copy) NSString              * TimeDisEM2;
@property (nonatomic , copy) NSString              * BatHighCap;
@property (nonatomic , copy) NSString              * BatUseCap;
@property (nonatomic , copy) NSString              * SetMode;
@property (nonatomic , copy) NSString              * SetPhase;
@property (nonatomic , copy) NSString              * SetFeed;
@property (nonatomic , copy) NSString              * BakBoxSN;
@property (nonatomic , copy) NSString              * SCBSN;
@property (nonatomic , copy) NSString              * BakBoxVer;
@property (nonatomic , copy) NSString              * SCBVer;
@property (nonatomic , copy) NSString              * BMUModel;
@property (nonatomic , copy) NSString              * GeneratorMode;
@property (nonatomic , copy) NSString              * GCSOCStart;
@property (nonatomic , copy) NSString              * GCSOCEnd;
@property (nonatomic , copy) NSString              * GCTimeStart;
@property (nonatomic , copy) NSString              * GCTimeEnd;
@property (nonatomic , copy) NSString              * GCOutputMode;
@property (nonatomic , copy) NSString              * GCChargePower;
@property (nonatomic , copy) NSString              * GCRatedPower;
@property (nonatomic , copy) NSString              * EmsLanguage;
@property (nonatomic , copy) NSString              * L1Priority;
@property (nonatomic , copy) NSString              * L2Priority;
@property (nonatomic , copy) NSString              * L3Priority;
@property (nonatomic , copy) NSString              * L1SocLimit;
@property (nonatomic , copy) NSString              * L2SocLimit;
@property (nonatomic , copy) NSString              * L3SocLimit;
@property (nonatomic , copy) NSString              * OnGridCap;
@property (nonatomic , copy) NSString              * StorageCap;
@property (nonatomic , copy) NSString              * BatReady;
@property (nonatomic , copy) NSString              * MeterACNegate;
@property (nonatomic , copy) NSString              * MeterDCNegate;
@property (nonatomic , copy) NSString              * Safe;
@property (nonatomic , copy) NSString              * SafetyType;
@property (nonatomic , copy) NSString              * PowerFact;
@property (nonatomic , copy) NSString              * Volt5MinAvg;
@property (nonatomic , copy) NSString              * Volt10MinAvg;
@property (nonatomic , copy) NSString              * TempThreshold;
@property (nonatomic , copy) NSString              * OutCurProtect;
@property (nonatomic , copy) NSString              * DCI;
@property (nonatomic , copy) NSString              * RCD;
@property (nonatomic , copy) NSString              * PvISO;
@property (nonatomic , copy) NSString              * ChargeBoostCur;
@property (nonatomic , copy) NSString              * Channel1;
@property (nonatomic , copy) NSString              * ControlMode1;
@property (nonatomic , copy) NSString              * StartTime1A;
@property (nonatomic , copy) NSString              * EndTime1A;
@property (nonatomic , copy) NSString              * StartTime1B;
@property (nonatomic , copy) NSString              * EndTime1B;
@property (nonatomic , copy) NSString              * Date1;
@property (nonatomic , copy) NSString              * ChargeSOC1;
@property (nonatomic , copy) NSString              * ChargeMode1;
@property (nonatomic , copy) NSString              * UPS1;
@property (nonatomic , copy) NSString              * SwitchOn1;
@property (nonatomic , copy) NSString              * SwitchOff1;
@property (nonatomic , copy) NSString              * Delay1;
@property (nonatomic , copy) NSString              * Duration1;
@property (nonatomic , copy) NSString              * Pause1;
@property (nonatomic , copy) NSString              * Channel2;
@property (nonatomic , copy) NSString              * ControlMode2;
@property (nonatomic , copy) NSString              * StartTime2A;
@property (nonatomic , copy) NSString              * EndTime2A;
@property (nonatomic , copy) NSString              * StartTime2B;
@property (nonatomic , copy) NSString              * EndTime2B;
@property (nonatomic , copy) NSString              * Date2;
@property (nonatomic , copy) NSString              * ChargeSOC2;
@property (nonatomic , copy) NSString              * ChargeMode2;
@property (nonatomic , copy) NSString              * UPS2;
@property (nonatomic , copy) NSString              * SwitchOn2;
@property (nonatomic , copy) NSString              * SwitchOff2;
@property (nonatomic , copy) NSString              * Delay2;
@property (nonatomic , copy) NSString              * Duration2;
@property (nonatomic , copy) NSString              * Pause2;
@property (nonatomic , copy) NSString              * NetType;
@property (nonatomic , copy) NSString              * Eirp;
@property (nonatomic , copy) NSString              * WifiSN;
@property (nonatomic , copy) NSString              * WifiSW;
@property (nonatomic , copy) NSString              * WifiHW;


@end

NS_ASSUME_NONNULL_END
