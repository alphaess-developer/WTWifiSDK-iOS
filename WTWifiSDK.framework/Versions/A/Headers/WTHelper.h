//
//  WTHelper.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTHelper : NSObject

/**
 带子节的字符串转为NSDictionary
 
 @return NSDictionary类型
 */
+ (NSDictionary *)convertToDictionaryWith:(NSString *)emsHex;

/**
 将符合通信协议NSData类型的数据转为NSDictionary
 
 @return NSDictionary类型
 */
+ (NSDictionary *)convertToDictionaryWithData:(NSData *)data;

/**
 带子节的字符串转为NSData
 
 @return NSData类型
 */
+ (NSData*)convertToDataWith:(NSString* )hexStr;

/**
 NSData 转  十六进制字符串

 @return NSString类型的十六进制字符串
 */
+ (NSString *)convertToHexStrWith:(NSData*)data;

/**
 根据所需携带的数据拼装EMS支持的通讯指令
 
 @return EMS 所能识别的通讯数据
 */
+ (NSData *)assembleEMSCommandWith:(NSData *)data;

/**
 NSData 转  十进制 UInteger
 
 @return 十进制
 */
+ (NSUInteger)convertToUIntegerWith:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
