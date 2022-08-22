//
//  WTWifiCenter.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import "WTSystemModel.h"
#import "WTRunningModel.h"
#import "WTSafetyModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WTWifiCenterDelegate <NSObject>

@optional
// WIFI模块热点连接已断开
- (void)didDisconnectedWith:(NSString *)ssid;

// WIFI模块热点已连接成功
- (void)didConnectedWith:(NSString *)ssid;

// 接收到EMS回传的系统信息
- (void)didReceiveEMSSystemInfo:(WTSystemModel *)info;

// 接收到EMS回传的运行信息
- (void)didReceiveEMSRunningInfo:(WTRunningModel *)info;

// 接收到EMS回传的安规信息
- (void)didReceiveEMSSafetyInfo:(WTSafetyModel *)info;
@end


@interface WTWifiCenter : NSObject



+ (instancetype)sharedInstance;

- (void)addDelegate:(id<WTWifiCenterDelegate>)delegate;

- (void)removeDelegate:(id<WTWifiCenterDelegate>)delegate;

- (void)startConfiguration;

/// 获取 WiFi 热点信息列表
- (void)fetchWifiList:(void (^)(NSArray * _Nullable list, NSError * _Nullable error))completionHandler;

// 配置采集器需要连接的无线路由器信息
/// ssid 无线网名称
/// password 无线网密码
- (void)wifiConfigurationWith:(NSString *)ssid password:(NSString *)password completionHandler:(void (^)(bool result, NSError * _Nullable error))completionHandler;

/// 获取采集器已连接的无线路由器信息
- (void)loadWifiConfiguration: (void (^)(NSDictionary * _Nullable result, NSError * _Nullable error))completionHandler;

/// 发送 EMS 查询系统信息指令
/// 通过 WTWifiCenterDelegate 中的 [didReceiveEMSSystemInfo] 回调数据
- (void)sendSystemInfoCommand;

/// 发送 EMS 查询运行信息指令
/// 通过 WTWifiCenterDelegate 中的 [didReceiveEMSRunningInfo] 回调数据
- (void)sendRunningInfoCommand;

/// 发送 EMS 查询安规信息指令
/// 通过 WTWifiCenterDelegate 中的 [didReceiveEMSSafetyInfo] 回调数据
- (void)sendSafetyInfoCommand;

@end

NS_ASSUME_NONNULL_END
