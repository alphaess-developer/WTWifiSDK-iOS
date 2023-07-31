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
@property (nonatomic , strong) UIButton *runningBtn;
@property (nonatomic , strong) UIButton *selfCheckBtn;
@property (nonatomic , strong) UIScrollView *scrollView;
@property (nonatomic , strong) UILabel *label;
@end

@implementation WTEMSInfoController


- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"EMS信息获取";
    self.view.backgroundColor = UIColor.whiteColor;

    
    [self.view addSubview:self.systemBtn];
    [self.view addSubview:self.runningBtn];
    [self.view addSubview:self.selfCheckBtn];
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

- (void)runningBtnTap {
    [[WTWifiCenter sharedInstance] loadRunningInfo:^( NSDictionary * _Nullable result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应系统信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"运行信息获取失败");
    }];
}

- (void)selfCheckBtnTap {
    [[WTWifiCenter sharedInstance] loadSelfCheckInfo:^(NSDictionary * _Nullable result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *labelText = [[NSString alloc] initWithFormat:@"已获取到EMS响应安规信息数据：\n %@", result];
            [self resizeLabelWith:labelText];
        });
    } failure:^(NSError * _Nullable error) {
        NSLog(@"安规信息获取失败");
    }];
}


#pragma mark - lazy initila

- (UIScrollView *)scrollView {
    if (_scrollView == nil) {
        _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(10, 150, UIScreen.mainScreen.bounds.size.width - 20, UIScreen.mainScreen.bounds.size.height - 200)];
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
        _systemBtn = [[UIButton alloc] initWithFrame:CGRectMake(20, 100, 100, 40)];
        [_systemBtn setTitle:@"EMS系统信息" forState:UIControlStateNormal];
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

- (UIButton *)runningBtn {
    if (_runningBtn == nil) {
        _runningBtn = [[UIButton alloc] initWithFrame:CGRectMake(130, 100, 100, 40)];
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

- (UIButton *)selfCheckBtn {
    if (_selfCheckBtn == nil) {
        _selfCheckBtn = [[UIButton alloc] initWithFrame:CGRectMake(240, 100, 100, 40)];
        [_selfCheckBtn setTitle:@"EMS安规自检信息" forState:UIControlStateNormal];
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


@end
