//
//  WTTYBle.h
//  WTWifiSDK
//
//  Created by xuzhonglin on 2024/9/30.
//

#import <Foundation/Foundation.h>
#import "WTEnums.h"
NS_ASSUME_NONNULL_BEGIN


@protocol WTTYBleDelegate <NSObject>


@optional

/// Callback method triggered after scanning nearby Wi-Fi networks.
///
/// @param wifiList An array containing the list of detected Wi-Fi networks.
///                 Each element in the array represents a Wi-Fi network, typically
///                 as a dictionary containing information like SSID, signal strength, etc.
///
/// @param uuid     A string representing the UUID (Universally Unique Identifier)
///                 associated with the Wi-Fi scan session or device. This can be
///                 used to uniquely identify the context in which the Wi-Fi scan was performed.
///
/// @param error    An NSError object that contains details about any error that occurred
///                 during the scanning process. If no error occurred, this value will be nil.
- (void)didScanWifiList:(NSArray *)wifiList uuid:(NSString *)uuid error:(NSError *)error;

/// Callback method for receiving the result of the Wi-Fi configuration over BLE (Bluetooth Low Energy).
///
/// @param deviceModel A dictionary containing information about the device that has been configured for Wi-Fi.
///                    This typically includes device details such as its identifier, Wi-Fi status, and other relevant information.
///
/// @param error       An NSError object that contains details about any error that occurred during the Wi-Fi configuration process.
///                    If the configuration was successful, this value will be nil.
- (void)didReceiveBLEWifiConfigDevice:(NSDictionary *)deviceModel error:(NSError *)error ;

@end


@interface WTTYBle : NSObject
@property (nonatomic, weak) id<WTTYBleDelegate> delegate;


+ (instancetype)sharedInstance;
/**
 * Initializes an instance with the specified key, secret, and debug mode.
 *
 * @param key      The unique key used for authentication or identification.
 *
 * @param secret   The secret corresponding to the key, used for secure operations.
 *
 * @param isDebug  A boolean indicating whether to enable debug mode.
 *                 If set to YES, additional logging and diagnostic information may be provided.
 *
 * @return An instance of the class initialized with the provided key, secret, and debug settings.
 */
- (instancetype)initWithKey:(NSString *)key secret:(NSString *)secret debug:(BOOL)isDebug;

/**
 Tuya user login or registration.

 @param countryCode  The country code, for example, "86" for China.
 
 @param uid          The anonymous ID, a unique identifier for the user.
                     It doesn't need to follow a specific format and serves as the user's unique identity.
 
 @param password     A random identifier associated with the account ID.
                     This identifier should remain consistent for the same account ID,
                     and it is not the user's actual password.
 
 @param createHome   A boolean flag indicating whether to create a default home for the user.
 
 @param success      A callback block executed when the request is successful.
                     It receives a result object containing the response data.
 
 @param failure      A callback block executed when the request fails.
                     It receives an NSError object describing the failure reason.
 */
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                            createHome:(BOOL)createHome
                               success:(void (^)(id result))success
                               failure:(void (^)(NSError *error))failure;

/**
 Starts scanning for nearby devices or signals.

 @param success A callback block that is executed when the scan is successful.
                The block receives a dictionary containing the scan results.
                The dictionary typically contains information such as device details,
                signal strength, and other relevant data.
                If no devices are found, the dictionary may be empty or null (nil).
 */
- (void)startScan: (void (^)(NSDictionary * _Nullable result))success;

/**
 * Fetches device information.
 * After the target device is scanned, this method can be used to query and display the product's configuration,
 * including its name and icon.
 *
 * @param productId The unique identifier of the product whose information is being queried.
 *
 * @param uuid      The universally unique identifier (UUID) of the target device.
 *
 * @param success   A callback block executed when the query is successful.
 *                  It receives a dictionary containing the device's details, such as the product name, icon, and other relevant information.
 *
 * @param failure   A callback block executed when the query fails.
 *                  It receives an NSError object describing the failure reason.
 */
- (void)getDeviceInfoWithProductId:(NSString *)productId
                      uuid:(NSString *)uuid
                        success:(void (^)(NSDictionary *dict))success
                        failure:(void (^)(NSError *error))failure;

/**
 * Retrieves a token for a Tuya device.
 *
 * @param homeId   The unique identifier of the user's home.
 *                 This is used to associate the token request with a specific home setup in the Tuya system.
 *
 * @param success  A callback block executed when the token retrieval is successful.
 *                 It receives a string representing the token for the device.
 *
 * @param failure  A callback block executed when the token retrieval fails.
 *                 It receives an NSError object describing the failure reason.
 */
- (void)getDeviceTokenWithHomeId:(long long)homeId success:(void(^)(NSString *token))success
                                failure:(void(^)(NSError *error))failure;

/**
 * Tuya dual-mode network configuration, used for connecting Bluetooth LE and Wi-Fi devices.
 * This method initiates the process of connecting a device using both Bluetooth and Wi-Fi.
 *
 * @param homeId    The unique identifier of the user's home where the device will be connected.
 *
 * @param ssid      The Wi-Fi SSID (network name) that the device will connect to.
 *
 * @param pwd       The Wi-Fi password for the specified SSID.
 *
 * @param uuid      The UUID (Universally Unique Identifier) of the Bluetooth LE device.
 *
 * @param productId The unique identifier of the product to be configured.
 *
 * @param success   A callback block executed when the connection is successfully established.
 *
 * @param failure   A callback block executed when the connection process fails.
 *                  It provides an error code (as an integer) and a description of the failure (as a string).
 */
- (void)startWifiActivatorWithHomeId:(long long)homeId
               wifiSsid:(NSString *)ssid
               wifiPwd:(NSString *)pwd
                uuid:(NSString *)uuid
                 productId:(NSString *)productId
               success:(void(^)(void))success
               failure:(void(^)(int errorCode, NSString *errorMessage))failure;


/**
 * Checks the online status of a device.
 * This method queries whether the device is locally connected via Bluetooth.
 *
 * @param uuid The UUID (Universally Unique Identifier) of the device to check.
 *
 * @return A boolean value indicating the device's online status.
 *         Returns YES if the device is online and connected locally via Bluetooth; otherwise, NO.
 */
- (BOOL)deviceIsOnline:(NSString *)uuid;

/*
 * Connects to an offline Bluetooth device.
 *
 * @param uuid        The UUID (Universally Unique Identifier) of the device to be connected.
 *
 * @param productId   The product key (identifier) associated with the device to establish the connection.
 *
 * @param success     A callback block executed when the device is successfully connected.
 *
 * @param failure     A callback block executed if the connection fails.
 */
- (void)connectBleDevice: (NSString *)uuid withProductKey:(NSString *)productId success:(void (^)(void))success failure:(void (^)(void))failure ;

/**
 * Disconnects from a Bluetooth device.
 *
 * @param uuid     The UUID (Universally Unique Identifier) of the device to be disconnected.
 *
 * @param success  A callback block executed when the device is successfully disconnected.
 *
 * @param failure  A callback block executed if the disconnection fails.
 *                 It receives an NSError object that provides details about the failure reason.
 */
- (void) disconnectBleDeviceWithUuid:(NSString *)uuid success:(void (^)(void))success
                                failure:(void (^)(NSError *error))failure;

/**
 * Stops the activation process.
 * This method should be called after the network configuration is complete.
 * It serves the same purpose as canceling the activation process on Android.
 */
- (void)stopActivator;

/**
 * stop scan
 */
- (void)stopScan;


/**
 * Removes a device from the system.
 * After the device is removed, it will enter a state awaiting network configuration
 * and will default to quick connect mode.
 *
 * @param deviceId  The unique identifier of the device to be removed.
 *
 * @param success   A callback block executed when the device removal is successful.
 *
 * @param failure   A callback block executed if the removal fails.
 *                  It receives an NSError object that provides details about the failure reason.
 */
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(void (^)(void))success
              failure:(void (^)(NSError *error))failure;


/**
 * Scans for nearby Wi-Fi networks.
 *
 * @param uuid     The UUID (Universally Unique Identifier) of the device initiating the scan.
 *
 * @param success  A callback block executed when the Wi-Fi scan is successful.
 *                 This block does not return any data.
 *
 * @param failure  A callback block executed if the scan fails.
 *                 It receives an NSError object that provides details about the failure reason.
 */
- (void)aroundSsidsScan:(NSString *)uuid success:(void(^)(void))success
                failure:(void(^)(NSError *error))failure;

/// Queries detailed information about a specific home.
///
/// @param homeId   The unique identifier of the home for which information is being requested.
///
/// @param success   A callback block executed when the query is successful.
///                  It receives a dictionary containing the home details, represented as `homeModel`.
///
/// @param failure   A callback block executed if the query fails.
///                  It receives an NSError object that provides details about the failure reason.
- (void)getHomeDataInfo:(long long)homeId success:(void (^)(NSDictionary  *homeModel))success
                failure:(void (^)(NSError *error))failure;

/// Retrieves a list of homes associated with the user.
///
/// @param success   A callback block executed when the query is successful.
///                  It receives an array of dictionaries, each representing a home in the user's account.
///
/// @param failure   A callback block executed if the query fails.
///                  It receives an NSError object that provides details about the failure reason.
- (void)getHomeDataListWithSuccess:(void (^)(NSArray<NSDictionary  *> *homes))success
                failure:(void (^)(NSError *error))failure;

/// Modifies the name of a specified device.
///
/// @param name       The new name to assign to the device.
///
/// @param deviceId   The unique identifier of the device whose name is being modified.
///
/// @param success    A callback block executed when the name modification is successful.
///                   This block does not return any data.
///
/// @param failure    A callback block executed if the name modification fails.
///                   It receives an NSError object that provides details about the failure reason.
- (void)modifyDeviceName:(NSString *)name withDeviceId:(NSString *)deviceId success:(void (^)(void))success
                 failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
