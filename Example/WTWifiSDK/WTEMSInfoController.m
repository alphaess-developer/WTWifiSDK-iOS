//
//  WTSystemInfoController.m
//  WTWifiSDK_Example
//
//  Created by cavan on 2022/8/17.
//  Copyright © 2022 Cavan. All rights reserved.
//

#import "WTEMSInfoController.h"
#import "WTWifiSDK/WTWifiCenter.h"


@interface WTEMSInfoController ()

@property (nonatomic , strong) UIButton *systemBtn;
@property (nonatomic , strong) UIButton *systemExtendBtn;
@property (nonatomic , strong) UIButton *runningBtn;
@property (nonatomic , strong) UIButton *runningExtendBtn;
@property (nonatomic , strong) UIButton *selfCheckBtn;
@property (nonatomic , strong) UIButton *italianSafetySelfCheckBtn;
@property (nonatomic , strong) UIScrollView *scrollView;
@property (nonatomic , strong) UILabel *label;
@end

@implementation WTEMSInfoController


- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"EMS信息获取";
    self.view.backgroundColor = UIColor.whiteColor;

    
    [self.view addSubview:self.systemBtn];
    [self.view addSubview:self.systemExtendBtn];
    [self.view addSubview:self.runningBtn];
    [self.view addSubview:self.runningExtendBtn];
    [self.view addSubview:self.selfCheckBtn];
    [self.view addSubview:self.italianSafetySelfCheckBtn];
    [self.view addSubview:self.scrollView];
}

- (void)resizeLabelWith:(NSString *)text {
    [self.label setText:text];
    [_label sizeToFit];
    CGSize baseSize = CGSizeMake(self.view.bounds.size.width - 20, CGFLOAT_MAX);
    CGSize labelsize = [_label sizeThatFits:baseSize];
    _scrollView.contentSize = CGSizeMake(0, labelsize.height);
}

-(UIStatusBarStyle)preferredStatusBarStyle {
    if (@available(iOS 13.0, *)) {
        return UIStatusBarStyleDarkContent;
    } else {
        return UIStatusBarStyleDefault;
    }
}

#pragma mark - Actions

- (void)systemBtnTap {
    [[WTWifiCenter sharedInstance] loadSystemInfo:^( NSDictionary * _Nullable result) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应系统信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"系统信息获取失败");
    }];
}

- (void)systemExtendBtnTap {
    [[WTWifiCenter sharedInstance] loadSystemInfoByExtendProtocol:^( NSDictionary * _Nullable result) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应系统扩展信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"系统扩展信息获取失败");
    }];
}

- (void)runningBtnTap {
    [[WTWifiCenter sharedInstance] loadRunningInfo:^( NSDictionary * _Nullable result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应运行信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"运行信息获取失败");
    }];
}

- (void)runningExtendBtnTap {
    [[WTWifiCenter sharedInstance] loadRunningInfoByExtendProtocol:^( NSDictionary * _Nullable result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应扩展运行信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"扩展运行信息获取失败");
    }];
}

- (void)selfCheckBtnTap {
    [[WTWifiCenter sharedInstance] loadAutoCheckInfo:^(NSDictionary * _Nullable result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应自检信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"自检信息获取失败");
    }];
}

- (void)italianSafetySelfCheckBtnTap {
    [[WTWifiCenter sharedInstance] loadAutoCheckInfoWithItalianSafety:^(NSDictionary * _Nullable result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应意大利安规信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"意大利安规信息获取失败");
    }];
}


#pragma mark - lazy initila

- (UIScrollView *)scrollView {
    if (_scrollView == nil) {
        _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(10, 250, UIScreen.mainScreen.bounds.size.width - 20, UIScreen.mainScreen.bounds.size.height - 300)];
        [_scrollView addSubview:self.label];
    }
    return _scrollView;
}

- (UILabel *)label {
    if (_label == nil) {
        _label = [[UILabel alloc] initWithFrame:CGRectMake(10, 0, UIScreen.mainScreen.bounds.size.width - 20,0)];
        [_label setTextColor:UIColor.grayColor];
        [_label setFont:[UIFont systemFontOfSize:12]];
        [_label setNumberOfLines:0];
    }
    return _label;
}

- (UIButton *)systemBtn {
    if (_systemBtn == nil) {
        _systemBtn = [[UIButton alloc] initWithFrame:CGRectMake(20, 100, 150, 40)];
        [_systemBtn setTitle:@"查询EMS系统信息" forState:UIControlStateNormal];
        [_systemBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [_systemBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_systemBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _systemBtn.layer.cornerRadius = 5;
        _systemBtn.layer.borderWidth = 0.5;
        [_systemBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_systemBtn addTarget:self action:@selector(systemBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _systemBtn;
}

- (UIButton *)systemExtendBtn {
    if (_systemExtendBtn == nil) {
        _systemExtendBtn = [[UIButton alloc] initWithFrame:CGRectMake(180, 100, 150, 40)];
        [_systemExtendBtn setTitle:@"查询EMS扩展系统信息" forState:UIControlStateNormal];
        [_systemExtendBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [_systemExtendBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_systemExtendBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _systemExtendBtn.layer.cornerRadius = 5;
        _systemExtendBtn.layer.borderWidth = 0.5;
        [_systemExtendBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_systemExtendBtn addTarget:self action:@selector(systemExtendBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _systemExtendBtn;
}

- (UIButton *)runningBtn {
    if (_runningBtn == nil) {
        _runningBtn = [[UIButton alloc] initWithFrame:CGRectMake(20, 150, 150, 40)];
        [_runningBtn setTitle:@"EMS运行信息" forState:UIControlStateNormal];
        [_runningBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [_runningBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_runningBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _runningBtn.layer.cornerRadius = 5;
        _runningBtn.layer.borderWidth = 0.5;
        [_runningBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_runningBtn addTarget:self action:@selector(runningBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _runningBtn;
}

- (UIButton *)runningExtendBtn {
    if (_runningExtendBtn == nil) {
        _runningExtendBtn = [[UIButton alloc] initWithFrame:CGRectMake(180, 150, 150, 40)];
        [_runningExtendBtn setTitle:@"EMS运行扩展信息" forState:UIControlStateNormal];
        [_runningExtendBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [_runningExtendBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_runningExtendBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _runningExtendBtn.layer.cornerRadius = 5;
        _runningExtendBtn.layer.borderWidth = 0.5;
        [_runningExtendBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_runningExtendBtn addTarget:self action:@selector(runningExtendBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _runningExtendBtn;
}

- (UIButton *)selfCheckBtn {
    if (_selfCheckBtn == nil) {
        _selfCheckBtn = [[UIButton alloc] initWithFrame:CGRectMake(20, 200, 150, 40)];
        [_selfCheckBtn setTitle:@"EMS自检信息查询" forState:UIControlStateNormal];
        [_selfCheckBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [_selfCheckBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_selfCheckBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _selfCheckBtn.layer.cornerRadius = 5;
        _selfCheckBtn.layer.borderWidth = 0.5;
        [_selfCheckBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_selfCheckBtn addTarget:self action:@selector(selfCheckBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _selfCheckBtn;
}

- (UIButton *)italianSafetySelfCheckBtn {
    if (_italianSafetySelfCheckBtn == nil) {
        _italianSafetySelfCheckBtn = [[UIButton alloc] initWithFrame:CGRectMake(180, 200, 150, 40)];
        [_italianSafetySelfCheckBtn setTitle:@"EMS意大利安规自检信息" forState:UIControlStateNormal];
        [_italianSafetySelfCheckBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [_italianSafetySelfCheckBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_italianSafetySelfCheckBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _italianSafetySelfCheckBtn.layer.cornerRadius = 5;
        _italianSafetySelfCheckBtn.layer.borderWidth = 0.5;
        [_italianSafetySelfCheckBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_italianSafetySelfCheckBtn addTarget:self action:@selector(italianSafetySelfCheckBtnTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _italianSafetySelfCheckBtn;
}

@end

