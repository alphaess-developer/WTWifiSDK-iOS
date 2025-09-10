//
//  WTWifiCenter.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import "WTUpdateModel.h"
#import "WTUpdateExtendModel.h"

NS_ASSUME_NONNULL_BEGIN


@interface WTWifiCenter : NSObject

#pragma mark - iOS API
/// Registers and fetches the nearby Wi-Fi list on iOS.
///
/// This method scans for available Wi-Fi networks, filters out duplicate SSIDs,
/// and keeps the network with the strongest signal for each SSID.
/// The signal strength is converted from a 0.0~1.0 scale to an approximate -100~0 dBm value.
/// Finally, the filtered list is stored in `WTConstants` for further use.
- (void)registerIOSfetchWifiList;

/// Connects to a specified Wi-Fi network using the given SSID and password.
///
/// @param result A callback block that returns a string indicating the connection result:
///               - @"success": The device successfully connected to the specified Wi-Fi.
///               - @"failed": The connection attempt failed.
///
/// @discussion
/// This method uses `NEHotspotConfigurationManager` to create and apply a hotspot configuration for the specified SSID.
/// If a password is provided, the connection uses WPA/WPA2 security; if no password is provided, it attempts to connect to an open network.
/// The method verifies the active Wi-Fi SSID to confirm whether the connection was successful.
///
/// @note This API is available on iOS 11.0 and later only. The user must grant permission for the connection attempt,
/// and the device may prompt the user to join the network.
- (void)connectSsidWithResult:(void (^)(NSString * _Nonnull result))result;

/// Removes a previously applied silent Wi-Fi configuration for the specified SSID.
///
/// @param result A callback block that returns a string indicating the result.
///               Returns "success" if the removal is successful,
///               or "failed" if the iOS version does not support this feature.
///
/// @discussion
/// This method uses NEHotspotConfigurationManager to remove a Wi-Fi configuration
/// that was previously added using NEHotspotConfiguration. This API is only available
/// on iOS 11.0 and later. On earlier versions, the operation is not supported.
- (void)removeConnectSsidWithResult:(void (^)(NSString * _Nonnull result))result;
#pragma mark - Elinker API
/// The Wifi SDK instance initial method.
+ (instancetype)sharedInstance;

/// Get device serial number from ap.
/// @param success  Callback the device sn.
/// @param failure  Callback when device sn load error.
- (void)fetchSystemSN:(void (^)(NSString * _Nullable ssid))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Get WiFi SSID list from WiFi collector device
/// @param success Callback WiFi SSID list, the list is an array of NSString.
/// @param failure Callback when load WiFi SSID list error.
- (void)fetchWifiList:(void (^)(NSArray * _Nullable list))success failure: (void (^)(NSError * _Nullable error)) failure __attribute__((deprecated("use fetchWifiInfoList")));

/// Get WiFi SSID list from WiFi collector device
/// @param success Callback WiFi SSID list, the list is an array of NSString.
/// @param failure Callback when load WiFi SSID list error.
- (void)fetchWifiInfoList:(void (^)(NSArray * _Nullable list))success failure: (void (^)(NSError * _Nullable error)) failure;

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

/// Load the energy storage management system information by extend protocol..
/// @param success Callback system info.
/// @param failure Callback error info.
- (void)loadSystemInfoByExtendProtocol:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load running information returned by the energy storage management system.
/// @param success Callback running info.
/// @param failure Callback error info.
- (void)loadRunningInfo:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load the energy storage management system running information by extend protocol.
/// @param success Callback running info.
/// @param failure Callback error info.
- (void)loadRunningInfoByExtendProtocol:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load battery and meter auto check information returned by the energy storage management system.
/// @param success Callback safety info.
/// @param failure Callback error info.
- (void)loadAutoCheckInfo:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure __attribute__((deprecated));

/// Load italian safety auto check information returned by the energy storage management system.
/// @param success Callback running info.
/// @param failure Callback error info.
- (void)loadAutoCheckInfoWithItalianSafety:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load safety information returned by the energy storage management system.
/// @param success Callback safety info.
/// @param failure Callback error info.
- (void)loadSafetyInfo:(void (^)(NSDictionary * _Nullable result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Update the related configuration parameters in the energy storage device.
/// @param data EMS configurations.
/// @param success Callback success when update success.
/// @param failure Callback error info when update failed.
- (void)updateEMSConfiguration:(WTUpdateModel *)data success:(void (^)(bool result))success failure: (void (^)(NSError * _Nullable error)) failure;


/// Update the related configuration parameters in the energy storage device by extend protocol.
/// @param data EMS configurations.
/// @param success Callback success when update success.
/// @param failure Callback error info when update failed.
- (void)updateEMSConfigurationByExtendProtocol:(WTUpdateExtendModel *)data success:(void (^)(bool result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Some special instructions based on the EMS protocol
/// [cmd] Command name
/// [parameter1] Command parameter 1
/// [parameter2] Command parameter 2
/// [parameter3] Command parameter 3
/// [description] Command description
- (void)sendSpecialCommand:(NSString *)cmd parameter1:(NSString *)param1 parameter2:(NSString * _Nullable)param2 parameter3:(NSString * _Nullable)param3 description: (NSString * _Nullable)desc success:(void (^)(bool result))success failure: (void (^)(NSError * _Nullable error)) failure;

/// Load tcp link status
- (void)loadTcpLinkStatus:(void (^)(bool result))status failure: (void (^)(NSError * _Nullable error)) failure;
@end

NS_ASSUME_NONNULL_END
