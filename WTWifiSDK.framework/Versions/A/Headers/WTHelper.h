//
//  WTHelper.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTHelper : NSObject

+ (NSDictionary *)convertToDictionaryWith:(NSString *)emsHex;
/**
 带子节的字符串转为NSData
 @return NSData类型
 */
+ (NSData*) convertToDataWith:(NSString* )hexStr;

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

@end

NS_ASSUME_NONNULL_END
