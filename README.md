## WTWifiSDK-iOS

WTWifiSDK is a framework for wifi configuration  **for** alphaess.

## 🔨 Requirements

The system requirement for WTWifiSDK is iOS 11.0+, and only support iOS device, not support iOS simulators.

## Install

`pod 'WTWifiSDK'`

## How to use?

* `#import "WTWifiSDK/WTWifiCenter.h"`

* You can get device serial number from ap, for example:

  ```objective-c
   [[WTWifiCenter sharedInstance] fetchSystemSN:^(NSString * _Nullable ssid) {
          dispatch_async(dispatch_get_main_queue(), ^{
             // Load ssid success, and refresh UI.
          });
      } failure:^(NSError * _Nullable error) {
          // Error
      }];
  ```

* Get the wifi ssid list from wifi collector device, for example:

  ```objective-c
   [[WTWifiCenter sharedInstance] fetchWifiList:^(NSArray * _Nullable list) {
          dispatch_async(dispatch_get_main_queue(), ^{
              self.ssids = list;
              [self.tableview reloadData];
          });
      } failure:^(NSError * _Nullable error) {
          // Error
      }];
  ```

* And if you want to config the local wifi for energy storage device, use this api:

  ```objective-c
   [[WTWifiCenter sharedInstance] wifiConfigurationWith:account password:password success:^(bool result) {
          
          if (result) {
              dispatch_async(dispatch_get_main_queue(), ^{
                 // Congratulations! you're successed!
              });
          } else {
              dispatch_async(dispatch_get_main_queue(), ^{
                 // Configure wrong. The reason maybe password is wrong.
              });
          }
      } failure:^(NSError * _Nullable error) {
         // Error
      }];
  ```

* If you want to see historical configuration then use Api like this：

  ```objective-c
   [[WTWifiCenter sharedInstance] loadWifiConfiguration:^(NSDictionary * _Nullable result) {
          dispatch_async(dispatch_get_main_queue(), ^{
              // Congratulations! you're successed!
          });
      } failure:^(NSError * _Nullable error) {
         // Error
      }]; 
  ```

* How to load the system information of energy management system?

  **Just call this api:**

  The result will be called back by `loadSystemInfo`.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
      [[WTWifiCenter sharedInstance] loadSystemInfo:^( NSDictionary * _Nullable result) {
          
          dispatch_async(dispatch_get_main_queue(), ^{
   // Congratulations! you're successed if the info not nil.
          });
      } failure:^(NSError * _Nullable error) {
         // Error
      }];
  ```
  
  **With the extend information:**
  
  We provide query methods for extended parameters as follows:
  
  ```objective-c
  [[WTWifiCenter sharedInstance] loadSystemInfoByExtendProtocol:^( NSDictionary * _Nullable result) {
          
          dispatch_async(dispatch_get_main_queue(), ^{
              // Congratulations! you're successed if the info not nil.
          });
      } failure:^(NSError * _Nullable error) {
          // Error
      }];
  ```
  
* How to load the running information of energy management system?

  **Just call this api:**

  The result will be called back by `loadRunningInfo`.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
   [[WTWifiCenter sharedInstance] loadRunningInfo:^( NSDictionary * _Nullable result) {
          dispatch_async(dispatch_get_main_queue(), ^{
              // Congratulations! you're successed if the info not nil.
          });
      } failure:^(NSError * _Nullable error) {
          // Error
      }];
  ```

  **With the extend information:**

  We provide query methods for extended parameters as follows:

  ```objective-c
   [[WTWifiCenter sharedInstance] loadRunningInfoByExtendProtocol:^( NSDictionary * _Nullable result) {
          dispatch_async(dispatch_get_main_queue(), ^{
              // Congratulations! you're successed if the info not nil.
          });
      } failure:^(NSError * _Nullable error) {
           // Error
      }];
  ```

* How to load the italian safety self-check information of energy management system?

  **Just call this api:**

  The result will be called back by `loadAutoCheckInfoWithItalianSafety`.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
    [[WTWifiCenter sharedInstance] loadAutoCheckInfoWithItalianSafety:^(NSDictionary * _Nullable result) {
          dispatch_async(dispatch_get_main_queue(), ^{
   // Congratulations! you're successed if the info not nil.
          });
      } failure:^(NSError * _Nullable error) {
         // Error
      }];
  ```

* How to configuration the energy storage device with parameters?

  ```objective-c
   WTUpdateModel *update = [[WTUpdateModel alloc] init];
      update.ACDC = @"3";
      update.CTRate = @"1";
      update.GridMeterCTE = @"0";
      update.Meter_CT_Select = @"2";
      update.OnGridCap = @"5000";
      update.ReliefMode = @"1";
      update.SafetyType = @"25";
      update.SelfUseOrEconomic = @"0";
      update.VPPMode = @"1";
      [[WTWifiCenter sharedInstance] updateEMSConfigurationByElinterWith:update success:^(bool result) {
          // Congratulations! you're successed.
      } failure:^(NSError * _Nullable error) {
          // Error
      }];
  ```

  **With the extend parameters:**

  We provide update methods for extended parameters as follows:

  ```objective-c
      WTUpdateExtendModel *update = [[WTUpdateExtendModel alloc] init];
  		update.BalconyMode = @"1";
  		update.OnGridPower = @"1022";
      update.NNShortDetect = @"2";
      [[WTWifiCenter sharedInstance] updateEMSConfigurationByExtendProtocol:update success:^(bool result) {
         // Congratulations! you're successed.
      } failure:^(NSError * _Nullable error) {
          // Error
      }];
  ```

## Issues

If you have any questions about the sdk, we welcome you to open issues. But when opening issues, please describe the problem replay scenario as clearly as possible, so that we can help you solve the problem more efficiently.

## Feature

We will support querying self-test information through EMS, including meter self-test information and battery self-test information. Although the SDK currently provides this API `loadAutoCheckInfo`, since the EMS system does not currently support it, you will always get null through this API. But don't worry, we will work on it all the time!

If you have any questions, you can contact me anytime.



