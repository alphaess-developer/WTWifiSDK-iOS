//
//  WTUpdateByExtendModel.h
//  WTWifiSDK
//
//  Created by cavan on 2023/11/8.
//

#import <Foundation/Foundation.h>
#import <JSONModel/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTUpdateExtendModel : JSONModel


/// System working mode setting
/// 0: spontaneous self-use mode
/// 1: performance mode
/// 2: off-grid mode
/// 3: forced charging mode
/// 4: custom mode
@property (nonatomic , copy) NSString              * BalconyMode;

/// Feeder power setting (W)
@property (nonatomic , copy) NSString              * OnGridPower;
/// Whether or not backup is connected to the load
/// 0: No setting
/// 1: Not connected to the load
/// 2: Connected to the load
@property (nonatomic , copy) NSString              * NNShortDetect;

/// Whether to set grid-connected charging and discharging.
/// (1 byte, bit 0 corresponds to grid-connected charging, bit 1 corresponds to grid-connected discharging, bit 2 indicates daily setting when 0, and weekly setting when 1)
@property (nonatomic , copy) NSString              * TIMEChaDisEN;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis1;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis2;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis3;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis4;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis5;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis6;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis7;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis8;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis9;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis10;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis11;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis12;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis13;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis14;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis15;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis16;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis17;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis18;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis19;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis20;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis21;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis22;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis23;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis24;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis25;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis26;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis27;
@property (nonatomic , copy) NSArray<NSNumber *>              * TIMEChaDis28;
@property (nonatomic , copy) NSString              * Channel1;
@property (nonatomic , copy) NSString              * ControlMode1;
@property (nonatomic , copy) NSString              * Date1;
@property (nonatomic , copy) NSString              * ChargeSOC1;
@property (nonatomic , copy) NSString              * ChargeMode1;
@property (nonatomic , copy) NSString              * UPS1;
@property (nonatomic , copy) NSString              * Delay1;
@property (nonatomic , copy) NSString              * Duration1;
@property (nonatomic , copy) NSString              * Pause1;
@property (nonatomic , copy) NSString              * FeedMode1;
@property (nonatomic , copy) NSString              * FeedValue1;
@property (nonatomic , copy) NSString              * SGEnable1;
@property (nonatomic , copy) NSArray              * DryTime1;
@property (nonatomic , copy) NSString              * Channel2;
@property (nonatomic , copy) NSString              * ControlMode2;
@property (nonatomic , copy) NSString              * ChargeMode2;
@property (nonatomic , copy) NSString              * Date2;
@property (nonatomic , copy) NSString              * ChargeSOC2;
@property (nonatomic , copy) NSString              * UPS2;
@property (nonatomic , copy) NSString              * Delay2;
@property (nonatomic , copy) NSString              * Duration2;
@property (nonatomic , copy) NSString              * Pause2;
@property (nonatomic , copy) NSString              * FeedMode2;
@property (nonatomic , copy) NSString              * FeedValue2;
@property (nonatomic , copy) NSString              * SGEnable2;
@property (nonatomic , copy) NSArray              * DryTime2;
@property (nonatomic, copy) NSNumber              * PhaseNegation;

@end

NS_ASSUME_NONNULL_END
