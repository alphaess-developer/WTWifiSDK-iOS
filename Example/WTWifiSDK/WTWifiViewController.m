//
//  WTWifiViewController.m
//  WTWifiSDK_Example
//
//  Created by cavan on 2022/9/1.
//  Copyright © 2022 Cavan. All rights reserved.
//

#import "WTWifiViewController.h"
#import <NetworkExtension/NetworkExtension.h>
#import "WTWifiSDK/WTWifiCenter.h"
#import "WTSSIDCell.h"
#import "WTEMSInfoController.h"
#import "WTWifiSDK/WTWifiSDK.h"
#import "CoreLocation/CLLocationManager.H"
#import "WTWifiSDK_Example-Swift.h"
#import <NetworkExtension/NetworkExtension.h>

@interface WTWifiViewController ()<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic , strong) UIButton *fetchPhoneWifiListButton;
@property (nonatomic , strong) UIButton *ssidButton;
@property (nonatomic , strong) UIButton *getPasswordButton;
@property (nonatomic , strong) UIButton *realSnButton;
@property (nonatomic , strong) UIButton *connectSsidButton;
@property (nonatomic , strong) UIButton *removeConnectSsidButton;
@property (nonatomic , strong) UIButton *resetPasswordBtn;
@property (nonatomic , strong) UIButton *getSsidTypeBtn;

@property (nonatomic , strong) UILabel *snLabel;
@property (nonatomic , strong) UIButton *button;
@property (nonatomic , strong) UIButton *loadSnBtn;
@property (nonatomic , strong) UIButton *loadConfigBtn;
@property (nonatomic , strong) UIButton *updateEMSBtn;
@property (nonatomic , strong) UIButton *updateEMSExtendBtn;
@property (nonatomic , strong) UIButton *sendSpecialCmdBtn;
@property (nonatomic , strong) UIButton *loadTcpLinkStatusBtn;
@property (nonatomic , strong) UITableView *tableview;
@property (nonatomic , strong) NSArray *ssids;

@property (nonatomic , copy) NSString *realSn;
@property (nonatomic , copy) NSString *passWord;
@end

@implementation WTWifiViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title = @"WIFI Config";
    self.view.backgroundColor = UIColor.whiteColor;
    
    [self.view addSubview:self.fetchPhoneWifiListButton];
    [self.view addSubview:self.ssidButton];
    [self.view addSubview:self.getPasswordButton];
    [self.view addSubview:self.realSnButton];
    [self.view addSubview:self.connectSsidButton];
    [self.view addSubview:self.removeConnectSsidButton];
    [self.view addSubview:self.resetPasswordBtn];
    [self.view addSubview:self.getSsidTypeBtn];

    [self.view addSubview:self.snLabel];
    [self.view addSubview:self.button];
    [self.view addSubview:self.loadSnBtn];
    [self.view addSubview:self.loadConfigBtn];
    [self.view addSubview:self.updateEMSBtn];
    [self.view addSubview:self.updateEMSExtendBtn];
    [self.view addSubview:self.sendSpecialCmdBtn];
    [self.view addSubview:self.loadTcpLinkStatusBtn];
    [self.view addSubview:self.tableview];
    
    CLLocationManager *locationManager = [[CLLocationManager alloc] init];
    [locationManager requestWhenInUseAuthorization];
    
    
//    // Request local network permission
//    if (@available(iOS 13.0, *)) {
//        [LocalNetworkAuthBridge requestAuthorization:^(BOOL granted) {
//            if (granted) {
//                NSLog(@"✅ Local network permission granted");
//            } else {
//                NSLog(@"❌ Local network permission denied");
//            }
//        }];
//    } else {
//        // Fallback on earlier versions
//    }

}

-(UIStatusBarStyle)preferredStatusBarStyle {
    if (@available(iOS 13.0, *)) {
        return UIStatusBarStyleDarkContent;
    } else {
        return UIStatusBarStyleDefault;
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
}

#pragma mark - Actions

- (void)fetchPhoneWifiListTap {
    
    NSArray *ARRAY = [WTWifiSDK getSsidArray];
    NSLog(@"ASDAD = %@",ARRAY);
//    [[WTWifiCenter sharedInstance] fetchWifiListByMobile:^(NSArray * _Nullable list) {
//        dispatch_async(dispatch_get_main_queue(), ^{
//            self.ssids = list;
//            [self.tableview reloadData];
//        });
//    }];
}

/// ALG001023120031AW
/// ALD001022038888
/// ALG001023120031EL
/// AL7011115010001EL
/// AL0001020011135
/// ALD072025080001AW
- (void)initSsidTap {
    [WTWifiSDK initSsid:@"ALG001023120031EL"];
//    [WTWifiSDK updatePassword:@"12345678"];

}

- (void)connectSsidTap {
    [[WTWifiCenter sharedInstance] connectSsidWithResult:^(NSString * _Nonnull result) {
        NSLog(@"connect result: %@",result);
    }];
}

- (void)removeConnectSsidTap {
    [[WTWifiCenter sharedInstance] removeConnectSsidWithResult:^(NSString * _Nonnull result) {
        NSLog(@"disconnect result: %@",result);
    }];
}

- (void)getPasswordTap {
   NSString *passW = [WTWifiSDK getPassword];
    self.passWord = passW;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.snLabel setText:[NSString stringWithFormat:@"current pwd: %@", passW]];
    });
}

- (void)getSnTap {
    NSString *realSn = [WTWifiSDK getSn];
    self.realSn = realSn;
     dispatch_async(dispatch_get_main_queue(), ^{
         [self.snLabel setText:[NSString stringWithFormat:@"current SN: %@", realSn]];
     });
}

- (void)getSsidTypeTap{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.snLabel setText:[NSString stringWithFormat:@"ssid type is %lu. 0: error, 1: old, 2: 18031, 3: self", (unsigned long)[WTWifiSDK getSsidType]]];
    });
}

- (void)resetPasswordTap{
    [WTWifiSDK resetDefaultPassword];
}

- (void) loadSnTap{
    [[WTWifiCenter sharedInstance] fetchSystemSN:^(NSString * _Nullable ssid) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.snLabel setText:[NSString stringWithFormat:@"current SN: %@", ssid]];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"search SN failed");
    }];
}

- (void) buttonTap{
    [[WTWifiCenter sharedInstance] fetchWifiList:^(NSArray * _Nullable list) {
        dispatch_async(dispatch_get_main_queue(), ^{
            self.ssids = list;
            [self.tableview reloadData];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"search WIFI list failed");
    }];
}

- (void)loadWifiConfiguration {
    WTEMSInfoController *controller = [[WTEMSInfoController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}

- (void)configurationWifiWith:(NSString *)account password:(NSString *)password {
    [[WTWifiCenter sharedInstance] wifiConfigurationWith:account password:password success:^(bool result) {
        
        if (result) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSString *title = @"Wi-Fi configuration succeeded!";
                UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message: nil preferredStyle:UIAlertControllerStyleAlert];
                UIAlertAction *ok = [UIAlertAction actionWithTitle:@"Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                    WTEMSInfoController *controller = [[WTEMSInfoController alloc] init];
                    [self.navigationController pushViewController:controller animated:YES];
                }];
                [alert addAction:ok];
                [self presentViewController:alert animated:YES completion:nil];
            });
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSString *title =  @"Wi-Fi configuration failed. Please try again.";
                NSString *message = @"Please confirm the password is correct or that you are connected to the device hotspot.";
                UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message: message preferredStyle:UIAlertControllerStyleAlert];
                UIAlertAction *ok = [UIAlertAction actionWithTitle:@"Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                   
                }];
                [alert addAction:ok];
                [self presentViewController:alert animated:YES completion:nil];
            });
        }
    } failure:^(NSError * _Nullable error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *title =  @"Wi-Fi configuration failed. Please try again.";
            NSString *message = @"Please confirm the password is correct or that you are connected to the device hotspot.";
            UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message: message preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction *ok = [UIAlertAction actionWithTitle:@"Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
               
            }];
            [alert addAction:ok];
            [self presentViewController:alert animated:YES completion:nil];
        });
    }];
   
}

- (void) updateEMSConfigurationTap{
    WTUpdateModel *update = [[WTUpdateModel alloc] init];
//    update.ACDC = @"3";
//    update.CTRate = @"1";
//    update.GridMeterCTE = @"0";
//    update.Meter_CT_Select = @"2";
//    update.OnGridCap = @"5000";
//    update.ReliefMode = @"1";
//    update.SafetyType = @"25";
//    update.SelfUseOrEconomic = @"0";
//    update.VPPMode = @"1";
//    // Enable generator
//    update.Generator = true;
    update.ModbusAddress = @"30";
    update.ModbusBaudrate = @"2";
    [[WTWifiCenter sharedInstance] updateEMSConfiguration:update success:^(bool result) {
        if (result) {
            NSLog(@"Configuration succeeded");
        } else {
            NSLog(@"Configuration failed");
        }
    } failure:^(NSError * _Nullable error) {
        NSLog(@"Configuration failed");
    }];
}

- (void) updateEMSExtendConfigurationTap{
    WTUpdateExtendModel *update = [[WTUpdateExtendModel alloc] init];
    
    update.NNShortDetect = @"0";
    update.OnGridPower = @"1022";
    update.NNShortDetect = @"0";
    update.TIMEChaDisEN = @"7";
    update.TIMEChaDis1 = [NSArray arrayWithObjects:@3,@29,@31,@1,@46,@68,@89, nil];
    update.Channel1 = @"1";
    update.ControlMode1 = @"3";
    update.Date1 = @"0";
    update.ChargeSOC1 = @"10";
    update.ChargeMode1 = @"0";
    update.UPS1 = @"1";
    update.Duration1 = @"16";
    update.Pause1 = @"17";
    update.FeedMode1 = @"2";
    update.FeedValue1 = @"16";
//    update.SGEnable1 = @"1";
    update.DryTime1 = [NSArray arrayWithObjects:@15,@30,@60,@90, nil];
    update.Channel2 = @"1";
    update.ControlMode2 = @"3";
    update.ChargeMode2 = @"0";
    update.Date2 = @"0";
    update.ChargeSOC2 = @"10";
    update.UPS2 = @"1";
    update.Delay2 = @"50";
    update.Duration2 = @"51";
    update.Pause2 = @"52";
    update.FeedMode2 = @"2";
    update.FeedValue2 = @"16";
    update.SGEnable2 = @"1";
    update.DryTime2 = [NSArray arrayWithObjects:@15,@30,@30,@45, nil];
    
    [[WTWifiCenter sharedInstance] updateEMSConfigurationByExtendProtocol:update success:^(bool result) {
        if (result) {
            NSLog(@"Extended parameters updated successfully");
        } else {
            NSLog(@"Failed to update extended parameters");
        }
    } failure:^(NSError * _Nullable error) {
        NSLog(@"Failed to update extended parameters");
    }];
}

- (void)sendSpecialCommandTap{

    [[WTWifiCenter sharedInstance] sendSpecialCommand:@"APPConnectEnd" parameter1:@"1" parameter2:nil parameter3:nil description:nil  success:^(bool result) {
        if (result) {
            NSLog(@"Special command \"APPConnectEnd\" responded successfully");
        } else {
            NSLog(@"Special command \"APPConnectEnd\" response failed");
        }
    } failure:^(NSError * _Nullable error) {
        NSLog(@"Special command \"APPConnectEnd\" response failed");
    }];
}

- (void)loadTcpLinkStatusTap{

    [[WTWifiCenter sharedInstance] loadTcpLinkStatus:^(bool result) {
        if (result) {
            NSLog(@"Device successfully connected to the server");
        } else {
            NSLog(@"Device failed to connect to the server");
        }
    } failure:^(NSError * _Nullable error) {
        NSLog(@"Device failed to connect to the server");
    }];
}

#pragma mark - lazy initila

// Common layout parameters
CGFloat leftColumnX = 30;
CGFloat rightColumnX = 230; // = 30 + 200;
CGFloat startY = 140;
CGFloat buttonWidth = 180;
CGFloat buttonHeight = 40;
CGFloat verticalSpacing = 20;
#pragma mark - Left column buttons (vertical)

- (UIButton *)fetchPhoneWifiListButton {
    if (_fetchPhoneWifiListButton == nil) {
        _fetchPhoneWifiListButton = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 0, buttonWidth, buttonHeight)];
        [_fetchPhoneWifiListButton setTitle:@"Get Wi-Fi list from phone" forState:UIControlStateNormal];
        [_fetchPhoneWifiListButton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        _fetchPhoneWifiListButton.layer.cornerRadius = 5;
        _fetchPhoneWifiListButton.layer.borderWidth = 0.5;
        _fetchPhoneWifiListButton.layer.borderColor = UIColor.grayColor.CGColor;
        [_fetchPhoneWifiListButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_fetchPhoneWifiListButton addTarget:self action:@selector(fetchPhoneWifiListTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _fetchPhoneWifiListButton;
}

- (UIButton *)ssidButton {
    if (_ssidButton == nil) {
        _ssidButton = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 1, buttonWidth, buttonHeight)];
        [_ssidButton setTitle:@"Pass SSID into SDK" forState:UIControlStateNormal];
        [_ssidButton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        _ssidButton.layer.cornerRadius = 5;
        _ssidButton.layer.borderWidth = 0.5;
        _ssidButton.layer.borderColor = UIColor.grayColor.CGColor;
        [_ssidButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_ssidButton addTarget:self action:@selector(initSsidTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _ssidButton;
}

- (UIButton *)connectSsidButton {
    if (_connectSsidButton == nil) {
        _connectSsidButton = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 2, buttonWidth, buttonHeight)];
        [_connectSsidButton setTitle:@"Connect to specified SSID" forState:UIControlStateNormal];
        [_connectSsidButton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        _connectSsidButton.layer.cornerRadius = 5;
        _connectSsidButton.layer.borderWidth = 0.5;
        _connectSsidButton.layer.borderColor = UIColor.grayColor.CGColor;
        [_connectSsidButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_connectSsidButton addTarget:self action:@selector(connectSsidTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _connectSsidButton;
}

- (UIButton *)removeConnectSsidButton {
    if (_removeConnectSsidButton == nil) {
        _removeConnectSsidButton = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 3, buttonWidth, buttonHeight)];
        [_removeConnectSsidButton setTitle:@"Remove connected SSID" forState:UIControlStateNormal];
        [_removeConnectSsidButton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        _removeConnectSsidButton.layer.cornerRadius = 5;
        _removeConnectSsidButton.layer.borderWidth = 0.5;
        _removeConnectSsidButton.layer.borderColor = UIColor.grayColor.CGColor;
        [_removeConnectSsidButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_removeConnectSsidButton addTarget:self action:@selector(removeConnectSsidTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _removeConnectSsidButton;
}

- (UIButton *)getPasswordButton {
    if (_getPasswordButton == nil) {
        _getPasswordButton = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 4, buttonWidth, buttonHeight)];
        [_getPasswordButton setTitle:@"Get password" forState:UIControlStateNormal];
        [_getPasswordButton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        _getPasswordButton.layer.cornerRadius = 5;
        _getPasswordButton.layer.borderWidth = 0.5;
        _getPasswordButton.layer.borderColor = UIColor.grayColor.CGColor;
        [_getPasswordButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_getPasswordButton addTarget:self action:@selector(getPasswordTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _getPasswordButton;
}

- (UIButton *)realSnButton {
    if (_realSnButton == nil) {
        _realSnButton = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 5, buttonWidth, buttonHeight)];
        [_realSnButton setTitle:@"Get real SN" forState:UIControlStateNormal];
        [_realSnButton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        _realSnButton.layer.cornerRadius = 5;
        _realSnButton.layer.borderWidth = 0.5;
        _realSnButton.layer.borderColor = UIColor.grayColor.CGColor;
        [_realSnButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_realSnButton addTarget:self action:@selector(getSnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _realSnButton;
}

- (UIButton *)getSsidTypeBtn {
    if (_getSsidTypeBtn == nil) {
        _getSsidTypeBtn = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 6, buttonWidth, buttonHeight)];
        [_getSsidTypeBtn setTitle:@"Get SSID type" forState:UIControlStateNormal];
        [_getSsidTypeBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_getSsidTypeBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _getSsidTypeBtn.layer.cornerRadius = 5;
        _getSsidTypeBtn.layer.borderWidth = 0.5;
        [_getSsidTypeBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_getSsidTypeBtn addTarget:self action:@selector(getSsidTypeTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _getSsidTypeBtn;
}

- (UIButton *)resetPasswordBtn {
    if (_resetPasswordBtn == nil) {
        _resetPasswordBtn = [[UIButton alloc] initWithFrame:CGRectMake(leftColumnX, startY + (buttonHeight + verticalSpacing) * 7, buttonWidth, buttonHeight)];
        [_resetPasswordBtn setTitle:@"Reset password to default" forState:UIControlStateNormal];
        [_resetPasswordBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_resetPasswordBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _resetPasswordBtn.layer.cornerRadius = 5;
        _resetPasswordBtn.layer.borderWidth = 0.5;
        [_resetPasswordBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_resetPasswordBtn addTarget:self action:@selector(resetPasswordTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _resetPasswordBtn;
}

- (UIButton *)loadSnBtn {
    if (_loadSnBtn == nil) {
        _loadSnBtn = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 0, buttonWidth, buttonHeight)];
        [_loadSnBtn setTitle:@"Query device SN" forState:UIControlStateNormal];
        [_loadSnBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_loadSnBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _loadSnBtn.layer.cornerRadius = 5;
        _loadSnBtn.layer.borderWidth = 0.5;
        [_loadSnBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_loadSnBtn addTarget:self action:@selector(loadSnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _loadSnBtn;
}

- (UIButton *)button {
    if (_button == nil) {
        _button = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 1, buttonWidth, buttonHeight)];
        [_button setTitle:@"Query Wi-Fi list" forState:UIControlStateNormal];
        [_button setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_button layer] setBorderColor:UIColor.grayColor.CGColor];
        _button.layer.cornerRadius = 5;
        _button.layer.borderWidth = 0.5;
        [_button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_button addTarget:self action:@selector(buttonTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _button;
}

- (UIButton *)loadConfigBtn {
    if (_loadConfigBtn == nil) {
        _loadConfigBtn = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 2, buttonWidth, buttonHeight)];
        [_loadConfigBtn setTitle:@"Query configured network info" forState:UIControlStateNormal];
        [_loadConfigBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_loadConfigBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _loadConfigBtn.layer.cornerRadius = 5;
        _loadConfigBtn.layer.borderWidth = 0.5;
        [_loadConfigBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_loadConfigBtn addTarget:self action:@selector(loadWifiConfiguration) forControlEvents:UIControlEventTouchUpInside];
    }
    return _loadConfigBtn;
}

- (UIButton *)updateEMSBtn {
    if (_updateEMSBtn == nil) {
        _updateEMSBtn = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 3, buttonWidth, buttonHeight)];
        [_updateEMSBtn setTitle:@"Update EMS parameters" forState:UIControlStateNormal];
        [_updateEMSBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_updateEMSBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _updateEMSBtn.layer.cornerRadius = 5;
        _updateEMSBtn.layer.borderWidth = 0.5;
        [_updateEMSBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_updateEMSBtn addTarget:self action:@selector(updateEMSConfigurationTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _updateEMSBtn;
}

- (UIButton *)updateEMSExtendBtn {
    if (_updateEMSExtendBtn == nil) {
        _updateEMSExtendBtn = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 4, buttonWidth, buttonHeight)];
        [_updateEMSExtendBtn setTitle:@"Update EMS extended parameters" forState:UIControlStateNormal];
        [_updateEMSExtendBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_updateEMSExtendBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _updateEMSExtendBtn.layer.cornerRadius = 5;
        _updateEMSExtendBtn.layer.borderWidth = 0.5;
        [_updateEMSExtendBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_updateEMSExtendBtn addTarget:self action:@selector(updateEMSExtendConfigurationTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _updateEMSExtendBtn;
}

- (UIButton *)sendSpecialCmdBtn {
    if (_sendSpecialCmdBtn == nil) {
        _sendSpecialCmdBtn = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 5, buttonWidth, buttonHeight)];
        [_sendSpecialCmdBtn setTitle:@"Send special command to EMS" forState:UIControlStateNormal];
        [_sendSpecialCmdBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_sendSpecialCmdBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _sendSpecialCmdBtn.layer.cornerRadius = 5;
        _sendSpecialCmdBtn.layer.borderWidth = 0.5;
        [_sendSpecialCmdBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_sendSpecialCmdBtn addTarget:self action:@selector(sendSpecialCommandTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _sendSpecialCmdBtn;
}

- (UIButton *)loadTcpLinkStatusBtn {
    if (_loadTcpLinkStatusBtn == nil) {
        _loadTcpLinkStatusBtn = [[UIButton alloc] initWithFrame:CGRectMake(rightColumnX, startY + (buttonHeight + verticalSpacing) * 6, buttonWidth, buttonHeight)];
        [_loadTcpLinkStatusBtn setTitle:@"Check device-cloud link status" forState:UIControlStateNormal];
        [_loadTcpLinkStatusBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_loadTcpLinkStatusBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _loadTcpLinkStatusBtn.layer.cornerRadius = 5;
        _loadTcpLinkStatusBtn.layer.borderWidth = 0.5;
        [_loadTcpLinkStatusBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_loadTcpLinkStatusBtn addTarget:self action:@selector(loadTcpLinkStatusTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _loadTcpLinkStatusBtn;
}

- (UILabel *)snLabel {
    if (_snLabel == nil) {
        _snLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 100, UIScreen.mainScreen.bounds.size.width - 20,30)];
        [_snLabel setTextColor:UIColor.blackColor];
        [_snLabel setFont:[UIFont systemFontOfSize:15]];
        [_snLabel setNumberOfLines:0];
        [_snLabel setTextAlignment:NSTextAlignmentCenter];
    }
    return _snLabel;
}

- (UITableView *)tableview {
    if (_tableview == nil) {
        _tableview = [[UITableView alloc] initWithFrame:CGRectMake(30, 600, UIScreen.mainScreen.bounds.size.width - 60, UIScreen.mainScreen.bounds.size.height - 500)];
        _tableview.tableFooterView = [UIView new];
        _tableview.delegate = self;
        _tableview.dataSource = self;
        _tableview.backgroundColor = UIColor.whiteColor;
    }
    return _tableview;
}

#pragma mark - UITableViewDelegate & UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.ssids.count;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    WTSSIDCell *cell = [WTSSIDCell cellWithTableView:tableView];
    cell.textLabel.text = [NSString stringWithFormat:@"%@" , self.ssids[indexPath.row]];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSString *ssid = self.ssids[indexPath.row];
    NSString *message = [[NSString alloc] initWithFormat:@"To configure Wi-Fi, please enter the password for %@", ssid];
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Network Configuration" message: message preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        [textField setPlaceholder:@"Please enter Wi-Fi password"];
    }];
    
    UIAlertAction *ok = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *pwd = alert.textFields.firstObject.text;
        if (pwd.length > 0) {
            [self configurationWifiWith:ssid password:pwd];
        }
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleDefault handler:nil];
    
    [alert addAction:cancel];
    [alert addAction:ok];
    [self presentViewController:alert animated:YES completion:nil];
}

@end
