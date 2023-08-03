//
//  WTWifiCenter.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import "WTUpdateModel.h"

NS_ASSUME_NONNULL_BEGIN


@interface WTWifiCenter : NSObject

/// The Wifi SDK instance initial method.
+ (instancetype)sharedInstance;

/// Get device serial number from ap.
/// @param success  Callback the device sn.
/// @param failure  Callback when device sn load error.
- (void)fetchSystemSN:(void (^)(NSString * _Nullable ssid))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Get WiFi SSID list from WiFi collector device
/// @param success Callback WiFi SSID list, the list is an array of NSString.
/// @param failure Callback when load WiFi SSID list error.
- (void)fetchWifiList:(void (^)(NSArray * _Nullable list))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Use the nearby wifi name and password to configure the collector so that it can access the Internet.
/// @param account Name of nearby Wifi that can access internet.
/// @param password Password of nearby Wifi that can access internet.
/// @param success Callback the configuration result, the result will be true if configuration success.
/// @param failure Callback the error info when configuration failed.
- (void)wifiConfigurationWith:(NSString *)account password:(NSString *)password success:(void (^)(bool result))success failure: (void (^)(NSError * _Nullable error)) failure ;

/// Get wifi module's history configurations.
/// @param success Callback the history configurations. The result contains some keys e.g. ssid/password/state, where the password keyword may be an empty string.
/// @param failure Callback the error info when load failed.
- (void)loadWifiConfiguration: (void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load system information returned by the energy storage management system.
/// @param success Callback system info.
/// @param failure Callback error info.
- (void)loadSystemInfo:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load running information returned by the energy storage management system.
/// @param success Callback running info.
/// @param failure Callback error info.
- (void)loadRunningInfo:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load safety information returned by the energy storage management system.
/// @param success Callback safety info.
/// @param failure Callback error info.
- (void)loadSelfCheckInfo:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Update the related configuration parameters in the energy storage device.
/// @param data EMS configurations.
/// @param success Callback success when update success.
/// @param failure Callback error info when update failed.
- (void)updateEMSConfigurationByElinterWith:(WTUpdateModel *)data success:(void (^)(bool result))success failure: (void (^)(NSError * _Nullable error)) failure;

@end

NS_ASSUME_NONNULL_END