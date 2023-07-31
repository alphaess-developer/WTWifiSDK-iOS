## WTWifiSDK-iOS

WTWifiSDK is a Framework for wifi configuration  **for** alphaess.

## 🔨 Requirements

The system requirement for WTWifiSDK is iOS 11.0+

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
  
* How to load the self-check information of energy management system?

  **Just call this api:**

  The result will be called back by `loadSelfCheckInfo`.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
    [[WTWifiCenter sharedInstance] loadSelfCheckInfo:^(NSDictionary * _Nullable result) {
          dispatch_async(dispatch_get_main_queue(), ^{
   // Congratulations! you're successed if the info not nil.
          });
      } failure:^(NSError * _Nullable error) {
         // Error
      }];
  ```
  
* And the last question, how to configuration the energy storage device with parameters?

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
  

## Issues

If you have any questions about the sdk, we welcome you to open issues. But when opening issues, please describe the problem replay scenario as clearly as possible, so that we can help you solve the problem more efficiently.

## Feature

We will work on a more stable implementation.



