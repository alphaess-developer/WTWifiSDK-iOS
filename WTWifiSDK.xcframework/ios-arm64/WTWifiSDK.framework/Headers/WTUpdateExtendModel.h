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
@property (nonatomic , copy) NSString              * TIMEChaDis1;
@property (nonatomic , copy) NSString              * TIMEChaDis2;
@property (nonatomic , copy) NSString              * TIMEChaDis3;
@property (nonatomic , copy) NSString              * TIMEChaDis4;
@property (nonatomic , copy) NSString              * TIMEChaDis5;
@property (nonatomic , copy) NSString              * TIMEChaDis6;
@property (nonatomic , copy) NSString              * TIMEChaDis7;
@property (nonatomic , copy) NSString              * TIMEChaDis8;
@property (nonatomic , copy) NSString              * TIMEChaDis9;
@property (nonatomic , copy) NSString              * TIMEChaDis10;
@property (nonatomic , copy) NSString              * TIMEChaDis11;
@property (nonatomic , copy) NSString              * TIMEChaDis12;
@property (nonatomic , copy) NSString              * TIMEChaDis13;
@property (nonatomic , copy) NSString              * TIMEChaDis14;
@property (nonatomic , copy) NSString              * TIMEChaDis15;
@property (nonatomic , copy) NSString              * TIMEChaDis16;
@property (nonatomic , copy) NSString              * TIMEChaDis17;
@property (nonatomic , copy) NSString              * TIMEChaDis18;
@property (nonatomic , copy) NSString              * TIMEChaDis19;
@property (nonatomic , copy) NSString              * TIMEChaDis20;
@property (nonatomic , copy) NSString              * TIMEChaDis21;
@property (nonatomic , copy) NSString              * TIMEChaDis22;
@property (nonatomic , copy) NSString              * TIMEChaDis23;
@property (nonatomic , copy) NSString              * TIMEChaDis24;
@property (nonatomic , copy) NSString              * TIMEChaDis25;
@property (nonatomic , copy) NSString              * TIMEChaDis26;
@property (nonatomic , copy) NSString              * TIMEChaDis27;
@property (nonatomic , copy) NSString              * TIMEChaDis28;
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
@property (nonatomic , copy) NSString              * DryTime1;
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
@property (nonatomic , copy) NSString              * DryTime2;

@end

NS_ASSUME_NONNULL_END
