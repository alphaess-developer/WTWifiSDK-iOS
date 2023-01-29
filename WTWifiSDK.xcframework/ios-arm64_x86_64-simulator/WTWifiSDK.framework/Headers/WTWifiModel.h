//
//  WTWifiModel.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTWifiModel : NSObject

/// 交流过压下拉选择值
+(NSArray *)overVs;
///交流欠压下拉选择值
+ (NSArray *)underVs;
///交流过频下拉选择值50HZ
+ (NSArray *)over50Fs;
///交流过频下拉选择值60HZ
+ (NSArray *)over60Fs;
///交流欠频下拉选择值50HZ
+ (NSArray *)under50Fs;
///交流欠频下拉选择值60HZ
+ (NSArray *)under60Fs;
/// 安规列表
+ (NSArray *)safetyList;
@end

NS_ASSUME_NONNULL_END
