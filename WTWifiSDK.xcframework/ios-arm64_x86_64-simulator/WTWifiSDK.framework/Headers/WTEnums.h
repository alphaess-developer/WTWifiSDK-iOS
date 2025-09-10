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

typedef NS_ENUM(NSUInteger, WTBLEOpMode) {
    WTBLEOpModeNull = 0,
    WTBLEOpModeSta,
    WTBLEOpModeSoftAP,
    WTBLEOpModeStaSoftAP,
};


typedef NS_ENUM(NSUInteger, WTWIFIType) {
    WTWIFITypeUnknown = 0,    ///< Not matched
    WTWIFITypeEtouchOld,      ///< old Etouch device
    WTWIFITypeEtouch18031,     ///< ETOUCH_SN_SUFFIX
    WTWIFITypeSelf,           ///< SELF_SN_SUFFIX
};



@interface WTEnums : NSObject

@end

NS_ASSUME_NONNULL_END
