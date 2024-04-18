//
//  WTViewController.m
//  WTWifiSDK
//
//  Created by Cavan on 08/16/2022.
//  Copyright (c) 2022 Cavan. All rights reserved.
//

#import "WTViewController.h"
#import "WTWifiViewController.h"

@interface WTViewController ()

@property (nonatomic , strong) UIButton *startWifiBtn;
@property (nonatomic , strong) UIButton *startBleBtn;

@end

@implementation WTViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.whiteColor;
    [self.view addSubview:self.startWifiBtn];
    [self.view addSubview:self.startBleBtn];

}

-(UIStatusBarStyle)preferredStatusBarStyle {
    if (@available(iOS 13.0, *)) {
        return UIStatusBarStyleDarkContent;
    } else {
        return UIStatusBarStyleDefault;
    }
}

#pragma mark - Actions

- (void) startWifiConfiguration{
    WTWifiViewController *controller = [[WTWifiViewController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}

- (void) startBleConfiguration{
    WTWifiViewController *controller = [[WTWifiViewController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}

#pragma mark - lazy initila


- (UIButton *)startWifiBtn {
    if (_startWifiBtn == nil) {
        _startWifiBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 200, 300, 40)];
        [_startWifiBtn setTitle:@"Start WIFI Configuration" forState:UIControlStateNormal];
        [_startWifiBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_startWifiBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _startWifiBtn.layer.cornerRadius = 5;
        _startWifiBtn.layer.borderWidth = 0.5;
        [_startWifiBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_startWifiBtn addTarget:self action:@selector(startWifiConfiguration) forControlEvents:UIControlEventTouchUpInside];
    }
    return _startWifiBtn;
}

- (UIButton *)startBleBtn {
    if (_startBleBtn == nil) {
        _startBleBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 280, 300, 40)];
        [_startBleBtn setTitle:@"Start Ble Configuration" forState:UIControlStateNormal];
        [_startBleBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_startBleBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _startBleBtn.layer.cornerRadius = 5;
        _startBleBtn.layer.borderWidth = 0.5;
        [_startBleBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_startBleBtn addTarget:self action:@selector(startBleConfiguration) forControlEvents:UIControlEventTouchUpInside];
    }
    return _startBleBtn;
}

@end
