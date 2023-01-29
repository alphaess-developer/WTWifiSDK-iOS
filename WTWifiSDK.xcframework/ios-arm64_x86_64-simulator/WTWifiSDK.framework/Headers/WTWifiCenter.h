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

/// The wifi module of the energy storage device hotspot connection has been disconnected.
/// @param ssid The name of the wifi module of the energy storage device.
- (void)didDisconnectedWith:(NSString *)ssid;

/// The wifi module of the energy storage device hotspot has been connected successfully.
/// @param ssid The name of the wifi module of the energy storage device.
- (void)didConnectedWith:(NSString *)ssid;

/// Receive system information returned by the energy storage management system.
/// @param info The keys and values of system information.
- (void)didReceiveEMSSystemInfo:(NSDictionary *)info;

/// Receive running information returned by the energy storage management system.
/// @param info The keys and values of running information.
- (void)didReceiveEMSRunningInfo:(NSDictionary *)info;

/// Receive safety information returned by the energy storage management system.
/// @param info The keys and values of safety information.
- (void)didReceiveEMSSafetyInfo:(NSDictionary *)info;

/// Energy management system related parameters have been successfully configured.
- (void)didUpdateEMSParametersSuccess;

/// An exception occurs when configuring parameters related to the energy management system.
/// At this point it is necessary to ensure that is the SSID of the energy management system connected correctly? or try calling [updateEMSConfigurationWith] multiple times.
- (void)didUpdateEMSParametersFailed;

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
/// @param completionHandler Callback WiFi SSID list, the list is an array of NSString.
- (void)fetchWifiList:(void (^)(NSArray * _Nullable list, NSError * _Nullable error))completionHandler;

/// Use the nearby wifi name and password to configure the collector so that it can access the Internet.
/// @param ssid Name of nearby Wifi that can access internet.
/// @param password Password of nearby Wifi that can access internet.
/// @param completionHandler Callback the configuration result, the result will be true if configuration success.
- (void)wifiConfigurationWith:(NSString *)ssid password:(NSString *)password completionHandler:(void (^)(bool result, NSError * _Nullable error))completionHandler;

/// Get collector history configuration.
/// @param completionHandler The result contains some keys e.g. ssid/password/state, where the password keyword may be an empty string.
- (void)loadWifiConfiguration:(void (^)(NSDictionary * _Nullable result, NSError * _Nullable error))completionHandler;

/// Send EMS commands to query the system information of energy storage devices.
/// The result will be called back by [didReceiveEMSSystemInfo] in WTWifiCenterDelegate.
/// But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.
- (void)sendSystemInfoCommand;

/// Send EMS commands to query the running information of energy storage devices.
/// The result will be called back by [didReceiveEMSRunningInfo] in WTWifiCenterDelegate.
/// But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.
- (void)sendRunningInfoCommand;

/// Send EMS commands to query the safety information of energy storage devices.
/// The result will be called back by [didReceiveEMSSafetyInfo] in WTWifiCenterDelegate.
/// But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.
- (void)sendSafetyInfoCommand;

/// Update the related configuration parameters in the energy storage device.
/// @param data Valid keys in energy management systems.
- (void)updateEMSConfigurationWith:(nonnull WTUpdateModel *)data;

@end

NS_ASSUME_NONNULL_END
