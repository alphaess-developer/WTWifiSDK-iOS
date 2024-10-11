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

/// 扫描附近WiFi列表
- (void)didScanWifiList:(NSArray *)wifiList uuid:(NSString *)uuid error:(NSError *)error;

/// 配网的结果
- (void)didReceiveBLEWifiConfigDevice:(NSDictionary *)deviceModel error:(NSError *)error ;

@end


@interface WTTYBle : NSObject
@property (nonatomic, weak) id<WTTYBleDelegate> delegate;


+ (instancetype)sharedInstance;

- (instancetype)initWithKey:(NSString *)key secret:(NSString *)secret debug:(BOOL)isDebug;
/**
 涂鸦用户登录注册
 countryCode    国家码，例如 86
 uid    匿名 ID，用户唯一标识，没有格式要求
 password    与账户 ID 对应的随机标识，同一个账户 ID 下保持用一个标识，而非用户的实际密码
 createHome    是否创建默认家庭
 success    接口发送成功回调
 failure    接口发送失败回调，error 表示失败原因
 */
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                            createHome:(BOOL)createHome
                               success:(void (^)(id result))success
                               failure:(void (^)(NSError *error))failure;

/// 开始扫描
- (void)startScan: (void (^)(NSDictionary * _Nullable result))success;

/**
 * 查询设备信息
 * 扫描到目标设备以后，可以通过查询显示产品配置的名称和图标。
 */
- (void)getDeviceInfoWithProductId:(NSString *)productId
                      uuid:(NSString *)uuid
                        success:(void (^)(NSDictionary *dict))success
                        failure:(void (^)(NSError *error))failure;

/**
 * 涂鸦获取token
 */
- (void)getDeviceTokenWithHomeId:(long long)homeId success:(void(^)(NSString *token))success
                                failure:(void(^)(NSError *error))failure;

/**
 * 涂鸦双模配网，使用此配网方式
 * connect Bluetooth LE and Wi-Fi device
 * 连接蓝牙 Wi-Fi 设备
 */
- (void)startWifiActivatorWithHomeId:(long long)homeId
               wifiSsid:(NSString *)ssid
               wifiPwd:(NSString *)pwd
                uuid:(NSString *)uuid
                 productId:(NSString *)productId
               success:(void(^)(void))success
               failure:(void(^)(int errorCode, NSString *errorMessage))failure;


/**
 * 判断设备在线状态
 * 查询设备蓝牙是否本地连接。
 */
- (BOOL)deviceIsOnline:(NSString *)uuid;

/*
 * 连接离线设备
 */
- (void)connectBleDevice: (NSString *)uuid withProductKey:(NSString *)productId success:(void (^)(void))success failure:(void (^)(void))failure ;

/**
 * 断开连接设备
 */
- (void) disconnectBleDeviceWithUuid:(NSString *)uuid success:(void (^)(void))success
                                failure:(void (^)(NSError *error))failure;

/**
 * 关闭轮询，在配网结束之后执行，等同于安卓的取消配网
 */
- (void)stopActivator;

/**
 * 停止扫描
 */
- (void)stopScan;


/**
 * 移除设备
 * 设备被移除后，会重新进入待配网状态，默认进入快连模式。
 */
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(void (^)(void))success
              failure:(void (^)(NSError *error))failure;


/**
 扫描附近的WiFi
 */
- (void)aroundSsidsScan:(NSString *)uuid success:(void(^)(void))success
                failure:(void(^)(NSError *error))failure;

/// 查询家庭的详细信息
- (void)getHomeDataInfo:(long long)homeId success:(void (^)(NSDictionary  *homeModel))success
                failure:(void (^)(NSError *error))failure;

/// 查询家庭列表
- (void)getHomeDataListWithSuccess:(void (^)(NSArray<NSDictionary  *> *homes))success
                failure:(void (^)(NSError *error))failure;

/// 修改设备名称
- (void)modifyDeviceName:(NSString *)name withDeviceId:(NSString *)deviceId success:(void (^)(void))success
                 failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
