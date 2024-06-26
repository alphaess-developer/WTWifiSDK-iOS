//
//  WTBleViewController.m
//  WTWifiSDK_Example
//
//  Created by cavan on 2024/4/18.
//  Copyright © 2024 Cavan. All rights reserved.
//

#import "WTBleViewController.h"
#import "WTWifiSDK/WTBleCenter.h"

@interface WTBleViewController ()<WTBleCenterDelegate>

@property (nonatomic , strong) UIButton *startScanBtn;
@property (nonatomic , strong) UIButton *stopScanBtn;
@property (nonatomic , strong) UIButton *connectBtn;
@property (nonatomic , strong) UIButton *disconnectBtn;
@property (nonatomic , strong) UIButton *authBtn;
@property (nonatomic , strong) UIButton *configNetworkBtn;
@property (nonatomic , strong) UIButton *loadSystemSNBtn;

@end

@implementation WTBleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.title = @"BLE 配置";
    self.view.backgroundColor = UIColor.whiteColor;
    
    [self.view addSubview:self.startScanBtn];
    [self.view addSubview:self.stopScanBtn];
    [self.view addSubview:self.connectBtn];
    [self.view addSubview:self.disconnectBtn];
    [self.view addSubview:self.authBtn];
    [self.view addSubview:self.configNetworkBtn];
    [self.view addSubview:self.loadSystemSNBtn];
    
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

- (void)connectBtnTap {
    [[WTBleCenter sharedInstance] connect:@"DDC48771-FF62-C002-E6EC-BBF6C0BDCBBA"];
}

- (void)disconnectBtnTap {
    [[WTBleCenter sharedInstance] disconnect];
}

- (void)authBtnTap {
    [[WTBleCenter sharedInstance] auth:@"12345678"];
}


- (void)configNetworkTap {
    [[WTBleCenter sharedInstance] configure:@"AlphaESS" password:@"AlphaESS"];
}


- (void)loadSystemSN {
    [[WTBleCenter sharedInstance] getInvSN];
}

#pragma mark - delegates

- (void)onDidReceiveDeviceResponseStatus:(WTBLEStatus)status {
    NSLog(@"onDidReceiveDeviceResponseStatus: %ld", status);
}

- (void)onDidReceiveCustomData:(NSDictionary *)result status:(WTBLEStatus)status {
    NSLog(@"onDidReceiveCustomData: %@", result);
}

- (void)onDidReceiveError:(NSInteger)errCode {
    
}

- (void)onPostConfigureParams:(WTBLEStatus)status {
    NSLog(@"onPostConfigureParams: %ld", status);
}

#pragma mark - lazy initila

- (UIButton *)startScanBtn {
    if (_startScanBtn == nil) {
        _startScanBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 150, 300, 40)];
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
        _stopScanBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 200, 300, 40)];
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
        _connectBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 250, 300, 40)];
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
        _disconnectBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 300, 300, 40)];
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

- (UIButton *)authBtn {
    if (_authBtn == nil) {
        _authBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 350, 300, 40)];
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

- (UIButton *)configNetworkBtn {
    if (_configNetworkBtn == nil) {
        _configNetworkBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 400, 300, 40)];
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
        _loadSystemSNBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 450, 300, 40)];
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

@end
