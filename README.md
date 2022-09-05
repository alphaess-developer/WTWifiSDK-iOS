## WTWifiSDK-iOS

-----

WTWifiSDK is a Framework for wifi configuration  **for** alphaess.

## 🔨 Requirements

The system requirement for WTWifiSDK is iOS 11.0+

## Install

---

`pod 'WTWifiSDK'`

## How to use?

---

* `#import "WTWifiSDK/WTWifiCenter.h"`

* Add or remove delegate with `WTWifiCenterDelegate`, for example:

  ```objective-c
   [[WTWifiCenter sharedInstance] addDelegate:self];
   [[WTWifiCenter sharedInstance] removeDelegate:self];
  ```

* Start the wifi configuration when the configuration view will appear, and release the wifi configuration when the view dealloc,  for example:

  ```objective-c
   [[WTWifiCenter sharedInstance] startConfiguration];
   [[WTWifiCenter sharedInstance] releaseConfiguration];
  ```

* Get the wifi ssid list from wifi collector device, for example:

  ```objective-c
  [[WTWifiCenter sharedInstance] fetchWifiList:^(NSArray * _Nullable list, NSError * _Nullable error) {
          self.ssids = list;
          [self.tableview reloadData];
  }];
  ```

* And if you want to config the local wifi for energy storage device, use this api:

  ```objective-c
  [[WTWifiCenter sharedInstance] wifiConfigurationWith:ssid password:password completionHandler:^(bool result, NSError * _Nullable error) {
          bool success = result && !error;
         if (success) {
                 // Congratulations! you're successed!
              }
      }];
  ```

* If you want to see historical configuration then use Api like this：

  ```objective-c
   [[WTWifiCenter sharedInstance] loadWifiConfiguration:^(NSDictionary * _Nullable result, NSError * _Nullable error) {
          bool success = result && !error;
         if (success) {
                  // Congratulations! you're successed!
              }
      }];
  ```

* How to load the system information of energy management system?

  **Step one:**

  Send EMS commands to query the system information of energy storage devices.

  ```objective-c
  [[WTWifiCenter sharedInstance] sendSystemInfoCommand];
  ```

  **Step two:**

  The result will be called back by [didReceiveEMSSystemInfo] in WTWifiCenterDelegate.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
  - (void)didReceiveEMSSystemInfo:(WTSystemModel *)info {
   // Congratulations! you're successed if the info not nil.
  }
  ```

* How to load the running information of energy management system?

  **Step one:**

  Send EMS commands to query the running information of energy storage devices.

  ```objective-c
  [[WTWifiCenter sharedInstance] sendRunningInfoCommand];
  ```

  **Step two:**

  The result will be called back by [didReceiveEMSRunningInfo] in WTWifiCenterDelegate.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
  - (void)didReceiveEMSRunningInfo:(WTSystemModel *)info {
   // Congratulations! you're successed if the info not nil.
  }
  ```

* How to load the safety information of energy management system?

  **Step one:**

  Send EMS commands to query the safety information of energy storage devices.

  ```objective-c
  [[WTWifiCenter sharedInstance] sendSafetyInfoCommand];
  ```

  **Step two:**

  The result will be called back by [didReceiveEMSSafetyInfo] in WTWifiCenterDelegate.But it should be noted that this is not a very stable callback, you may try to send the command multiple times after ensuring that the direct connection is successful.

  ```objective-c
  - (void)didReceiveEMSSafetyInfo:(WTSystemModel *)info {
   // Congratulations! you're successed if the info not nil.
  }
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
  [[WTWifiCenter sharedInstance] updateEMSConfigurationWith:update];
  ```

  **Note:**

  When the configuration success, the delegate method [didUpdateEMSParametersSuccess] will be called. And otherwise, the delegate method [didUpdateEMSParametersFailed] will be called.

## Issues

---

If you have any questions about the sdk, we welcome you to open issues. But when opening issues, please describe the problem replay scenario as clearly as possible, so that we can help you solve the problem more efficiently.

## Feature

---

We will work on a more stable implementation.



