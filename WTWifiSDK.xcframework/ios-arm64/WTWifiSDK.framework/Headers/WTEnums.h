//
//  WTEnums.h
//  WTWifiSDK
//
//  Created by cavan on 2024/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, WTBLEStatus) {
    WTBleStatusSuccess = 0,
    WTBleStatusFailed = 100,
    WTBleStatusInvalidRequest,
    WTBleStatusWriteFailed,
    WTBleStatusInvalidData,
    WTBleStatusBLEStateDisable,
    WTBleStatusException,
};


@interface WTEnums : NSObject

@end

NS_ASSUME_NONNULL_END
