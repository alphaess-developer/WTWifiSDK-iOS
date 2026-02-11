//
//  WTBleViewController.m
//  WTWifiSDK_Example
//
//  Created by cavan on 2024/4/18.
//  Copyright © 2024 Cavan. All rights reserved.
//

#import "WTBleViewController.h"
#import "WTWifiSDK/WTBleCenter.h"
#import <WTWifiSDK/WTWifiSDK.h>

@interface WTBleViewController ()<WTBleCenterDelegate>

@property (nonatomic , strong) UIButton *startScanBtn;
@property (nonatomic , strong) UIButton *stopScanBtn;
@property (nonatomic , strong) UIButton *connectBtn;
@property (nonatomic , strong) UIButton *disconnectBtn;
@property (nonatomic , strong) UIButton *authBtn;
@property (nonatomic , strong) UIButton *configNetworkBtn;
@property (nonatomic , strong) UIButton *loadSystemSNBtn;
@property (nonatomic , strong) UIButton *sucureBton;

@property (nonatomic , strong) UIButton *changeAuthPasswordBtn;
@property (nonatomic , strong) UIButton *updateAPNBtn;
@property (nonatomic , strong) UIButton *getAPNBtn;


@end

@implementation WTBleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.title = @"BLE Config";
    self.view.backgroundColor = UIColor.whiteColor;
    
    [self.view addSubview:self.startScanBtn];
    [self.view addSubview:self.stopScanBtn];
    [self.view addSubview:self.connectBtn];
    [self.view addSubview:self.disconnectBtn];
    [self.view addSubview:self.authBtn];
    [self.view addSubview:self.configNetworkBtn];
    [self.view addSubview:self.loadSystemSNBtn];
    [self.view addSubview:self.sucureBton];
    [self.view addSubview:self.changeAuthPasswordBtn];
    [self.view addSubview:self.updateAPNBtn];
    [self.view addSubview:self.getAPNBtn];


    [WTBleCenter sharedInstance].delegate = self;
}

#pragma mark - Actions

- (void) startScanBtnTap{
    [[WTBleCenter sharedInstance] startScan:^(NSDictionary * _Nullable result) {
        NSLog(@"%@", result);
    }];
}


- (void) stopScanBtnTap{
    [[WTBleCenter sharedInstance] stopScan];
}

/// ALG001023120031AW   F59BBC1D-B9EA-3CBB-C03D-EC86B7DCE982
/// ALG001023120031EL CBCA6B2D-295F-D228-E48D-14EB82854ED5
/// {
//name = ALG001023120031EL;
//rssi = "-49";
//uuid = "ECD6FC94-3E45-5C49-E473-D48F12D2381D";
//}
- (void)connectBtnTap {
    [[WTBleCenter sharedInstance] connect:@"ECD6FC94-3E45-5C49-E473-D48F12D2381D"];
}

- (void)disconnectBtnTap {
    [[WTBleCenter sharedInstance] disconnect];
}

- (void)authBtnTap {
    NSString *passW = [WTWifiSDK getPassword];
    [[WTBleCenter sharedInstance] auth:passW];
}


- (void)configNetworkTap {
    [[WTBleCenter sharedInstance] configure:@"AlphaESS" password:@"AlphaESS123"];
}


- (void)loadSystemSN {
    [[WTBleCenter sharedInstance] getInvSN];
}


- (void)changeAuthPasswordTap {
    [[WTBleCenter sharedInstance] updateApPassword:@"A12345678"];
    [WTWifiSDK updatePassword:@"A12345678"];
}

-(void)sucureBtonTap {
    [[WTBleCenter sharedInstance] negotiateSecurity];
}


- (void)updateAPN {
    [[WTBleCenter sharedInstance] updateAPNConfigure:@"mobile" user:@"" password:@""];

}

- (void)getAPN {
    [[WTBleCenter sharedInstance] fetchAPNConfigure];

}

#pragma mark - delegates

- (void)onDidReceiveDeviceResponseStatus:(WTBLEStatus)status {
    NSLog(@"onDidReceiveDeviceResponseStatus: %ld", status);
}

- (void)onDidReceiveCustomData:(NSDictionary *)result status:(WTBLEStatus)status {
    NSLog(@"onDidReceiveCustomData: %@", result);
}

- (void)onDidReceiveError:(NSInteger)errCode {
    NSLog(@"onDidReceiveError: %ld", errCode);

}

- (void)onPostConfigureParams:(WTBLEStatus)status {
    NSLog(@"onPostConfigureParams: %ld", status);
}

#pragma mark - lazy initila

- (UIButton *)startScanBtn {
    if (_startScanBtn == nil) {
        _startScanBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 150, 300, 40)];
        [_startScanBtn setTitle:@"Start Scan" forState:UIControlStateNormal];
        [_startScanBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_startScanBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _startScanBtn.layer.cornerRadius = 5;
        _startScanBtn.layer.borderWidth = 0.5;
        [_startScanBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_startScanBtn addTarget:self action:@selector(startScanBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _startScanBtn;
}


- (UIButton *)stopScanBtn {
    if (_stopScanBtn == nil) {
        _stopScanBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 200, 300, 40)];
        [_stopScanBtn setTitle:@"Stop Scan" forState:UIControlStateNormal];
        [_stopScanBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_stopScanBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _stopScanBtn.layer.cornerRadius = 5;
        _stopScanBtn.layer.borderWidth = 0.5;
        [_stopScanBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_stopScanBtn addTarget:self action:@selector(stopScanBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _stopScanBtn;
}

- (UIButton *)connectBtn {
    if (_connectBtn == nil) {
        _connectBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 250, 300, 40)];
        [_connectBtn setTitle:@"Connect" forState:UIControlStateNormal];
        [_connectBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_connectBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _connectBtn.layer.cornerRadius = 5;
        _connectBtn.layer.borderWidth = 0.5;
        [_connectBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_connectBtn addTarget:self action:@selector(connectBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _connectBtn;
}

- (UIButton *)disconnectBtn {
    if (_disconnectBtn == nil) {
        _disconnectBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 300, 300, 40)];
        [_disconnectBtn setTitle:@"Ble disconnect" forState:UIControlStateNormal];
        [_disconnectBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_disconnectBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _disconnectBtn.layer.cornerRadius = 5;
        _disconnectBtn.layer.borderWidth = 0.5;
        [_disconnectBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_disconnectBtn addTarget:self action:@selector(disconnectBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _disconnectBtn;
}

- (UIButton *)sucureBton {
    if (_sucureBton == nil) {
        _sucureBton = [[UIButton alloc] initWithFrame:CGRectMake(50, 350, 300, 40)];
        [_sucureBton setTitle:@"Security" forState:UIControlStateNormal];
        [_sucureBton setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_sucureBton layer] setBorderColor:UIColor.grayColor.CGColor];
        _sucureBton.layer.cornerRadius = 5;
        _sucureBton.layer.borderWidth = 0.5;
        [_sucureBton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_sucureBton addTarget:self action:@selector(sucureBtonTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _sucureBton;
}

- (UIButton *)authBtn {
    if (_authBtn == nil) {
        _authBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 400, 300, 40)];
        [_authBtn setTitle:@"Ble Auth" forState:UIControlStateNormal];
        [_authBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_authBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _authBtn.layer.cornerRadius = 5;
        _authBtn.layer.borderWidth = 0.5;
        [_authBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_authBtn addTarget:self action:@selector(authBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _authBtn;
}

- (UIButton *)changeAuthPasswordBtn {
    if (_changeAuthPasswordBtn == nil) {
        _changeAuthPasswordBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 450, 300, 40)];
        [_changeAuthPasswordBtn setTitle:@"change password" forState:UIControlStateNormal];
        [_changeAuthPasswordBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_changeAuthPasswordBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _changeAuthPasswordBtn.layer.cornerRadius = 5;
        _changeAuthPasswordBtn.layer.borderWidth = 0.5;
        [_changeAuthPasswordBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_changeAuthPasswordBtn addTarget:self action:@selector(changeAuthPasswordTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _changeAuthPasswordBtn;
}

- (UIButton *)configNetworkBtn {
    if (_configNetworkBtn == nil) {
        _configNetworkBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 500, 300, 40)];
        [_configNetworkBtn setTitle:@"Ble Network Configuration" forState:UIControlStateNormal];
        [_configNetworkBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_configNetworkBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _configNetworkBtn.layer.cornerRadius = 5;
        _configNetworkBtn.layer.borderWidth = 0.5;
        [_configNetworkBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_configNetworkBtn addTarget:self action:@selector(configNetworkTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _configNetworkBtn;
}

- (UIButton *)loadSystemSNBtn {
    if (_loadSystemSNBtn == nil) {
        _loadSystemSNBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 550, 300, 40)];
        [_loadSystemSNBtn setTitle:@"Ble Load System SN" forState:UIControlStateNormal];
        [_loadSystemSNBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_loadSystemSNBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _loadSystemSNBtn.layer.cornerRadius = 5;
        _loadSystemSNBtn.layer.borderWidth = 0.5;
        [_loadSystemSNBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_loadSystemSNBtn addTarget:self action:@selector(loadSystemSN) forControlEvents:UIControlEventTouchUpInside];
    }
    return _loadSystemSNBtn;
}

- (UIButton *)updateAPNBtn {
    if (_updateAPNBtn == nil) {
        _updateAPNBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 600, 300, 40)];
        [_updateAPNBtn setTitle:@"update APN" forState:UIControlStateNormal];
        [_updateAPNBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_updateAPNBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _updateAPNBtn.layer.cornerRadius = 5;
        _updateAPNBtn.layer.borderWidth = 0.5;
        [_updateAPNBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_updateAPNBtn addTarget:self action:@selector(updateAPN) forControlEvents:UIControlEventTouchUpInside];
    }
    return _updateAPNBtn;
}

- (UIButton *)getAPNBtn {
    if (_getAPNBtn == nil) {
        _getAPNBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 650, 300, 40)];
        [_getAPNBtn setTitle:@"get APN" forState:UIControlStateNormal];
        [_getAPNBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_getAPNBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _getAPNBtn.layer.cornerRadius = 5;
        _getAPNBtn.layer.borderWidth = 0.5;
        [_getAPNBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_getAPNBtn addTarget:self action:@selector(getAPN) forControlEvents:UIControlEventTouchUpInside];
    }
    return _getAPNBtn;
}

@end
