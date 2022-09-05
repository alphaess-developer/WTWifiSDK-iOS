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

@property (nonatomic , strong) UIButton *startBtn;

@end

@implementation WTViewController


- (void)viewDidLoad
{
    [super viewDidLoad];

    self.view.backgroundColor = UIColor.whiteColor;
    [self.view addSubview:self.startBtn];

}

-(UIStatusBarStyle)preferredStatusBarStyle {
    if (@available(iOS 13.0, *)) {
        return UIStatusBarStyleDarkContent;
    } else {
        return UIStatusBarStyleDefault;
    }
}

#pragma mark - Actions

- (void) startConfiguration{
    WTWifiViewController *controller = [[WTWifiViewController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}


#pragma mark - lazy initila


- (UIButton *)startBtn {
    if (_startBtn == nil) {
        _startBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 200, 200, 40)];
        [_startBtn setTitle:@"开始WIFI配置" forState:UIControlStateNormal];
        [_startBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_startBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _startBtn.layer.cornerRadius = 5;
        _startBtn.layer.borderWidth = 0.5;
        [_startBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_startBtn addTarget:self action:@selector(startConfiguration) forControlEvents:UIControlEventTouchUpInside];
    }
    return _startBtn;
}


@end
