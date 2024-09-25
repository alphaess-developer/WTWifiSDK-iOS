//
//  WTBleCenter.h
//  WTWifiSDK
//
//  Created by cavan on 2024/3/28.
//

#import <Foundation/Foundation.h>
#import "WTEnums.h"
#import "CoreBluetooth/CoreBluetooth.h"

NS_ASSUME_NONNULL_BEGIN


@protocol WTBleCenterDelegate <NSObject>


@optional

/// Connection to device successful callback
- (void)onConnectStatusUpdated:(WTBLEStatus)status;

/// Callback for sending network configuration instructions (determine if sent successfully)
- (void)onPostConfigureParams:(WTBLEStatus)status;

/// After sending business instructions, the device responds to the callback
/// For example: After sending the network configuration command, the network configuration result is called back (to determine whether the network configuration is successful)
/// staConnectionStatus: When currently in Station mode(WTBLEOpModeSta), 0 means there is Wi-Fi connection, otherwise there is no Wi-Fi connection
- (void)onDidReceiveDeviceResponseOpMode:(WTBLEOpMode)mode staConnectionStatus:(NSInteger)staConnectionStatus  status:(WTBLEStatus)status;

/// Callback for scanning surrounding WiFi
- (void)onDeviceScanResponse:(NSArray<NSDictionary *> *)scanResults
                      status:(WTBLEStatus)status;

/// Callback for sending business instructions (to determine if the sending is successful)
/// emsHex: Transparent Data (Converting Inverter Data Packets to Hexadecimal Strings)
/// Note: The 'emsHex' data contains the original data packets of the corresponding manufacturer's inverter communication protocol.
/// The string format is: AA5502…, which means each HEX value is represented by two bytes without spaces.
- (void)onPostCommandResult:(NSDictionary *)result status:(WTBLEStatus)status;

/// Callback for received business instructions
/// emsHex: Transparent Data (Converting Inverter Data Packets to Hexadecimal Strings)
/// Note: The 'emsHex' data contains the original data packets of the corresponding manufacturer's inverter communication protocol.
/// The string format is: AA5502…, which means each HEX value is represented by two bytes without spaces.
- (void)onDidReceiveCustomData:(NSDictionary *)result status:(WTBLEStatus)status;

/// Failure to send business command device reception
- (void)onDidReceiveError:(NSInteger)errCode;

/// "Unexpected disconnection event callback for connected device."
- (void)centralManager:(CBCentralManager *)central didFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/// Callback for actively disconnecting from a connected device event.
- (void)centralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/// Callback for changes in device connection status.
- (void)centralManagerDidUpdateState:(nonnull CBCentralManager *)central;

/// sign认证密码错误，断开连接监听方法
- (void)centralManager:(CBCentralManager *)central didDisconnectWithSignPwdErrorPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

@end


@interface WTBleCenter : NSObject

@property (nonatomic, weak) id<WTBleCenterDelegate> delegate;


+ (instancetype)sharedInstance;

/// Start Bluetooth scanning.
- (void)startScan: (void (^)(NSDictionary * _Nullable result))success;

/// Stop Bluetooth scanning.
- (void)stopScan;

/// Connect device.
/// Note: Before connecting, initialization is required. After connection, Bluetooth password verification [bleAuth] must be called immediately. Only after verification passes can subsequent operations be performed. Otherwise, the device will disconnect automatically.
/// uuid:  The UUID of the device in the list of scanned Bluetooth devices.
- (void)connect: (NSString *)uuid;

/// Disconnect device.
- (void)disconnect;


/// Clear connection cache.
- (void)close;

/// Bluetooth password verification, must be called immediately after successful connection [bleConnectDevice].
/// password：The Bluetooth password of the device.
- (void)auth:(NSString *)password;

/// Mesh network configuration
/// ssid: wifi name
/// password: wifi password
- (void)meshConfigure:(NSString *)ssid withPasswrod:(NSString *)password;

/// Remove device from Mesh network
- (void)meshRemove;

/// Get device manufacturer code
- (void)loadInverterCode;

/// Get system sn.
- (void)getInvSN __attribute__((deprecated));

/// Inverter transparent data
/// emsHex: Transparent Data (Converting Inverter Data Packets to Hexadecimal Strings)
/// Note: The 'emsHex' data contains the original data packets of the corresponding manufacturer's inverter communication protocol.
/// The string format is: AA5502…, which means each HEX value is represented by two bytes without spaces.
- (void)passthroughInverterData: (NSString *)emsHex;


/// Modify wireless network connection password, Bluetooth connection password
/// oldPassword: Old password, example: 1234
/// newPassword: New password, example: 1234
- (void)modifyPassword:(NSString *)oldPassword withPasswrod:(NSString *)newPassword;


/// Set APN information for devices with mobile network communication capabilities
/// After calling this interface, the device will restart to take effect. The APP and other calling parties need to add corresponding reminders. In addition, this setting information generally needs to be consulted with the SIM card supplier to obtain.
/// apnName: Access point name, which is the name of the wireless network access point
/// userName: User name
/// password: User password
- (void)updateAPNConfigure:(NSString *)apnName user:(NSString *)userName password:(NSString *)password;


/// Obtain APN information for devices with mobile network communication capabilities
/// After calling this interface, the device will restart to take effect. The APP and other calling parties need to add corresponding reminders. In addition, this setting information generally needs to be consulted with the SIM card supplier to obtain.
/// apnName: Access point name, which is the name of the wireless network access point
/// userName: User name
/// password: User password
- (void)fetchAPNConfigure;

/// Set the connection address for device communication with the cloud
/// After calling this interface, the device will restart to take effect. The APP and other calling parties need to add corresponding reminders. In addition, this setting information generally needs to be consulted with the SIM card supplier to obtain.
/// mode: Supported types are http, https, tcp, udp, mqtt, mqtts
/// serverIp: Domain name or IP
/// port: Port number
/// userName: User name
/// password: User password
- (void)updateServerConfigure:(NSString *)mode server:(NSString *)serverIp port:(NSString *)port user:(NSString *)userName password:(NSString *)password;

/// Bluetooth network configuration
/// ssid: Wi-Fi name
/// password: Wi-Fi password
- (void)configure:(NSString *)ssid password:(NSString *)password;

/// Device scans surrounding Wi-Fi
- (void)aroundSsidsScan;

/// Get the current status of the device
/// The device status will be received in the didReceiveDeviceStatusResponse callback
- (void)fetchDeviceStatus;


@end

NS_ASSUME_NONNULL_END
