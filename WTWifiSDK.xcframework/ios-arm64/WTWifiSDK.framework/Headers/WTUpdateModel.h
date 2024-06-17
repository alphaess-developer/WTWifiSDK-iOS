//
//  WTUpdateModel.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/25.
//

#import <Foundation/Foundation.h>
#import <JSONModel/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTUpdateModel : JSONModel
@property (nonatomic , copy) NSString              * Time;
@property (nonatomic , copy) NSString              * StorageCap;
@property (nonatomic , copy) NSString              * OnGridCap;
@property (nonatomic , copy) NSString              * SetFeed;
@property (nonatomic , copy) NSString              * ACDC;
@property (nonatomic , copy) NSString              * Meter_CT_Select;
@property (nonatomic , copy) NSString              * GridMeterCTE;
@property (nonatomic , copy) NSString              * CTRate;
@property (nonatomic , copy) NSString              * PVMeterCTE;
@property (nonatomic , copy) NSString              * PVMeterCTRate;
@property (nonatomic , copy) NSString              * MeterDCInstallPosition;
@property (nonatomic , copy) NSString              * SafetyType;
@property (nonatomic , copy) NSString              * SafeSub;
@property (nonatomic , copy) NSString              * BatReady;
@property (nonatomic , copy) NSString              * ChargeWorkDays;
@property (nonatomic , copy) NSString              * GridCharge;
@property (nonatomic , copy) NSString              * CtrDis;
@property (nonatomic , copy) NSString              * TimeChaF1;
@property (nonatomic , copy) NSString              * TimeChaE1;
@property (nonatomic , copy) NSString              * TimeChaF2;
@property (nonatomic , copy) NSString              * TimeChaE2;
@property (nonatomic , copy) NSString              * TimeDisF1;
@property (nonatomic , copy) NSString              * TimeDisE1;
@property (nonatomic , copy) NSString              * TimeDisF2;
@property (nonatomic , copy) NSString              * TimeDisE2;
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
@property (nonatomic , copy) NSString              * ChargeWeekend;
@property (nonatomic , copy) NSString              * GridChargeWE;
@property (nonatomic , copy) NSString              * CtrDisWE;
@property (nonatomic , copy) NSString              * TimeChaFWE1;
@property (nonatomic , copy) NSString              * TimeChaEWE1;
@property (nonatomic , copy) NSString              * TimeChaFWE2;
@property (nonatomic , copy) NSString              * TimeChaEWE2;
@property (nonatomic , copy) NSString              * TimeDisFWE1;
@property (nonatomic , copy) NSString              * TimeDisEWE1;
@property (nonatomic , copy) NSString              * TimeDisFWE2;
@property (nonatomic , copy) NSString              * TimeDisEWE2;
@property (nonatomic , copy) NSString              * BatHighCapWE;
@property (nonatomic , copy) NSString              * BatUseCapWE;
@property (nonatomic , assign) BOOL                Generator;
@property (nonatomic , copy) NSString              * GeneratorMode;
@property (nonatomic , copy) NSString              * GCSOCStart;
@property (nonatomic , copy) NSString              * GCSOCEnd;
@property (nonatomic , copy) NSString              * GCTimeStart;
@property (nonatomic , copy) NSString              * GCTimeEnd;
@property (nonatomic , copy) NSString              * GCOutputMode;
@property (nonatomic , copy) NSString              * GCChargePower;
@property (nonatomic , copy) NSString              * GCRatedPower;
@property (nonatomic , copy) NSString              * GCAvailablePercentage;
@property (nonatomic , copy) NSString              * GCATS;
@property (nonatomic , copy) NSString              * DG_Cap;
@property (nonatomic , copy) NSString              * BackUpBox;
@property (nonatomic , copy) NSString              * L1Priority;
@property (nonatomic , copy) NSString              * L2Priority;
@property (nonatomic , copy) NSString              * L3Priority;
@property (nonatomic , copy) NSString              * L1SocLimit;
@property (nonatomic , copy) NSString              * L2SocLimit;
@property (nonatomic , copy) NSString              * L3SocLimit;
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
@property (nonatomic , copy) NSString              * ChargeMode2;
@property (nonatomic , copy) NSString              * StartTime2A;
@property (nonatomic , copy) NSString              * EndTime2A;
@property (nonatomic , copy) NSString              * StartTime2B;
@property (nonatomic , copy) NSString              * EndTime2B;
@property (nonatomic , copy) NSString              * Date2;
@property (nonatomic , copy) NSString              * ChargeSOC2;
@property (nonatomic , copy) NSString              * UPS2;
@property (nonatomic , copy) NSString              * SwitchOn2;
@property (nonatomic , copy) NSString              * SwitchOff2;
@property (nonatomic , copy) NSString              * Delay2;
@property (nonatomic , copy) NSString              * Duration2;
@property (nonatomic , copy) NSString              * Pause2;
@property (nonatomic , copy) NSString              * InstallModule;
@property (nonatomic , copy) NSString              * StringAE;
@property (nonatomic , copy) NSString              * StringBE;
@property (nonatomic , copy) NSString              * StringCE;
@property (nonatomic , copy) NSString              * SelfUseOrEconomic;
@property (nonatomic , copy) NSString              * ReliefMode;
@property (nonatomic , copy) NSString              * VPPMode;
@property (nonatomic , copy) NSString              * OVRVolt;
@property (nonatomic , copy) NSString              * OVRTime;
@property (nonatomic , copy) NSString              * UVRVolt;
@property (nonatomic , copy) NSString              * UVRTime;
@property (nonatomic , copy) NSString              * OFRFreq;
@property (nonatomic , copy) NSString              * OFRTime;
@property (nonatomic , copy) NSString              * UFRFreq;
@property (nonatomic , copy) NSString              * UFRTime;
@property (nonatomic , copy) NSString              * RecoverDelay;
@property (nonatomic , copy) NSString              * VoltReactRise;
@property (nonatomic , copy) NSString              * VoltActRise;
@property (nonatomic , copy) NSString              * PowerFactor;
@property (nonatomic , copy) NSString              * ISOFlag;
@property (nonatomic , copy) NSString              * ManualRecoverFlag;
@property (nonatomic , copy) NSString              * ManualRecoverSet;
@property (nonatomic , copy) NSString              * StorageBreakerSpecs;
@property (nonatomic , copy) NSString              * IPMethod;
@property (nonatomic , copy) NSString              * LocalIP;
@property (nonatomic , copy) NSString              * SubnetMask;
@property (nonatomic , copy) NSString              * Gateway;
@property (nonatomic , copy) NSString              * ModbusAddress;
@property (nonatomic , copy) NSString              * ModbusBaudrate;
@property (nonatomic , copy) NSString              * INVModel;
@property (nonatomic , copy) NSString              * Parallel_EN;
@property (nonatomic , copy) NSString              * Parallel_Selection;
@property (nonatomic , copy) NSString              * Parallel_Mode;
@property (nonatomic , copy) NSString              * UPSReserveEN;
@property (nonatomic , copy) NSString              * Load_cut_out_en;
@property (nonatomic , copy) NSString              * Cutoff_Soc;
@property (nonatomic , copy) NSString              * Wakeup_Soc;

@end

NS_ASSUME_NONNULL_END
