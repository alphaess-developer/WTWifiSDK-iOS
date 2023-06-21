//
//  WTWifiCenter.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import "WTUpdateModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WTWifiCenterDelegate <NSObject>

@optional


@end


@interface WTWifiCenter : NSObject

/// The Wifi SDK instance initial method.
+ (instancetype)sharedInstance;

/// Add a delegate to WTWifiCenter, and WTWifiCenter supports adding multiple delegates.
/// @param delegate Must follow WTWifiCenterDelegate.
- (void)addDelegate:(id<WTWifiCenterDelegate>)delegate;

/// Remove a delegate from WTWifiCenter,
/// @param delegate Must follow WTWifiCenterDelegate.
- (void)removeDelegate:(id<WTWifiCenterDelegate>)delegate;

/// Initialize the internal business logic of the wifi sdk, this method must be called when the SDK is initialized.
- (void)startConfiguration;

/// Release the internal business logic of the wifi sdk, this method must be called when the SDK is no longer used
- (void)releaseConfiguration;

/// Get WiFi SSID list from WiFi collector device
/// @param success Callback WiFi SSID list, the list is an array of NSString.
/// @param failure Callback when load WiFi SSID list error.
- (void)fetchWifiList:(void (^)(NSString * _Nullable ssid,NSArray * _Nullable list))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Use the nearby wifi name and password to configure the collector so that it can access the Internet.
/// @param account Name of nearby Wifi that can access internet.
/// @param password Password of nearby Wifi that can access internet.
/// @param success Callback the configuration result, the result will be true if configuration success.
/// @param failure Callback the error info when configuration failed.
- (void)wifiConfigurationWith:(NSString *)account password:(NSString *)password success:(void (^)(NSString * _Nullable ssid,bool result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Get wifi module's history configurations.
/// @param success Callback the history configurations. The result contains some keys e.g. ssid/password/state, where the password keyword may be an empty string.
/// @param failure Callback the error info when load failed.
- (void)loadWifiConfiguration: (void (^)(NSString * _Nullable ssid,NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load system information returned by the energy storage management system.
/// @param success Callback system info.
/// @param failure Callback error info.
- (void)loadSystemInfo:(void (^)(NSString * _Nullable ssid, NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;


/// Load running information returned by the energy storage management system.
/// @param success Callback running info.
/// @param failure Callback error info.
- (void)loadRunningInfo:(void (^)(NSString * _Nullable ssid, NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;


/// Load safety information returned by the energy storage management system.
/// @param success Callback safety info.
/// @param failure Callback error info.
- (void)loadSafetyInfo:(void (^)(NSString * _Nullable ssid, NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Update the related configuration parameters in the energy storage device.
/// @param data EMS configurations.
/// @param success Callback success when update success.
/// @param failure Callback error info when update failed.
- (void)updateEMSConfigurationByElinterWith:(WTUpdateModel *)data success:(void (^)(NSString * _Nullable ssid, bool result))success failure: (void (^)(NSError * _Nullable error)) failure;

@end

NS_ASSUME_NONNULL_END
