//
//  WTWifiSDK.h
//  WTWifiSDK
//
//  Created by cavan on 2024/4/12.
//

#ifndef WTWifiSDK_h
#define WTWifiSDK_h

#import "CoreBluetooth/CoreBluetooth.h"
#import "WTWifiSDK/WTWifiCenter.h"
#import "WTWifiSDK/WTWifiModel.h"
#import "WTWifiSDK/WTUpdateModel.h"
#import "WTWifiSDK/WTUpdateExtendModel.h"
#import "WTWifiSDK/WTBleCenter.h"
#import "WTWifiSDK/WTWifiSDK.h"

typedef NS_ENUM(NSUInteger, WTBLEStatus) {
    WTBleStatusSuccess = 0,
    WTBleStatusFailed = 100,
    WTBleStatusInvalidRequest,
    WTBleStatusWriteFailed,
    WTBleStatusInvalidData,
    WTBleStatusBLEStateDisable,
    WTBleStatusException,
};



#endif /* WTWifiSDK_h */
