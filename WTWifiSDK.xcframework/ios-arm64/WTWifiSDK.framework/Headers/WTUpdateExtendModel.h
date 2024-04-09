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

/// APP side WIFI network configuration completion flag
/// 0: Default value.  APP network configuration setting failed;
/// 1: APP network configuration setting successful
@property (nonatomic , copy) NSString              * APPConnectEnd;

@end

NS_ASSUME_NONNULL_END
