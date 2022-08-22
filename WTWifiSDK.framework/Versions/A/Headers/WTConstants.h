//
//  WTConstants.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// API 请求超时时间
FOUNDATION_EXPORT CGFloat const TIMEOUT_REQUEST;
// WIFI模块Ping间隔时间
FOUNDATION_EXPORT CGFloat const PING_TIME;
// CMD 查询指令轮询时间
FOUNDATION_EXPORT CGFloat const EMS_CMD_RESEND_TIME;
// ZLG Socket 重连时间
FOUNDATION_EXPORT CGFloat const SOCKET_RECONNECT_TIME;
// EMS 系统信息获取指令
FOUNDATION_EXPORT NSString * const EMS_SYSTEM_CMD;
// EMS 运行信息获取指令
FOUNDATION_EXPORT NSString * const EMS_RUNNING_CMD;
// EMS 安规信息获取指令
FOUNDATION_EXPORT NSString * const EMS_SAFETY_CMD;
// 易联品牌名称字符串
FOUNDATION_EXPORT NSString * const EL_BRAND;
// 获取易联模块信息,可根据是否返回”E-LINTER”,判断当前是否为易联设备
FOUNDATION_EXPORT NSString * const EL_DEV;
// 获取易联 WiFi 热点信息列表
FOUNDATION_EXPORT NSString * const EL_WIFI_LIST;
// 配置易联采集器需要连接的无线路由器信息
FOUNDATION_EXPORT NSString * const EL_STA_SET;
// 获取易联采集器已连接的无线路由器信息
FOUNDATION_EXPORT NSString * const EL_STA_GET;
// 获取易联 Wi-Fi Stick AP 模式的设备信息，即获取采集器自身无线热点信息
FOUNDATION_EXPORT NSString * const EL_AP_GET;
// 易联透传调试接口，采集器收到该指令后将完整的数据包发送给逆变器
FOUNDATION_EXPORT NSString * const EL_FDBG;

// 获取周立功 Wi-Fi Stick AP 模式的设备信息，即获取采集器自身无线热点信息
FOUNDATION_EXPORT NSString * const ZLG_AP_GET;
// 获取周立功 WiFi 热点信息列表/配置需要连接的无线路由器信息/查询已连接的无线路由器信息
FOUNDATION_EXPORT NSString * const ZLG_WIFI_STA;
// 获取周立功串口参数
FOUNDATION_EXPORT NSString * const ZLG_SERIAL_DATA;
// 获取周立功系统状态信息
FOUNDATION_EXPORT NSString * const ZLG_BRIEF_INFO;
// 周立功设备重启Api
FOUNDATION_EXPORT NSString * const ZLG_TAKE_EFFECT;
// 周立功请求头 Authorization
FOUNDATION_EXPORT NSString * const ZLG_AUTHORIZATION;
// 周立功 SOCKET IP
FOUNDATION_EXPORT NSString * const ZLG_SOCKET_IP;
// 周立功 SOCKET 端口号
FOUNDATION_EXPORT NSInteger const ZLG_SOCKET_PORT;

@interface WTConstants : NSObject


@end

NS_ASSUME_NONNULL_END
