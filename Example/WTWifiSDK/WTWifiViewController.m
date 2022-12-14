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

@interface WTWifiViewController ()<WTWifiCenterDelegate, UITableViewDelegate, UITableViewDataSource>

@property (nonatomic , strong) UIButton *button;
@property (nonatomic , strong) UIButton *loadConfigBtn;
@property (nonatomic , strong) UIButton *updateEMSBtn;
@property (nonatomic , strong) UITableView *tableview;
@property (nonatomic , strong) NSArray *ssids;

@end

@implementation WTWifiViewController


-(void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [[WTWifiCenter sharedInstance] addDelegate:self];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title = @"WIFI配置";
    self.view.backgroundColor = UIColor.whiteColor;
    [[WTWifiCenter sharedInstance] startConfiguration];
   
    [self.view addSubview:self.button];
    [self.view addSubview:self.loadConfigBtn];
    [self.view addSubview:self.updateEMSBtn];
    [self.view addSubview:self.tableview];

}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [[WTWifiCenter sharedInstance] removeDelegate:self];
}

- (void)dealloc {
    NSLog(@"开始dealloc");
    [[WTWifiCenter sharedInstance] releaseConfiguration];
    [[WTWifiCenter sharedInstance] removeDelegate:self];
}

-(UIStatusBarStyle)preferredStatusBarStyle {
    if (@available(iOS 13.0, *)) {
        return UIStatusBarStyleDarkContent;
    } else {
        return UIStatusBarStyleDefault;
    }
}

#pragma mark - Actions

- (void) buttonTap{
    [[WTWifiCenter sharedInstance] fetchWifiList:^(NSArray * _Nullable list, NSError * _Nullable error) {
        self.ssids = list;
        [self.tableview reloadData];
    }];
}

- (void)loadWifiConfiguration {
    [[WTWifiCenter sharedInstance] loadWifiConfiguration:^(NSDictionary * _Nullable result, NSError * _Nullable error) {
        bool success = result && !error;
        NSString *title = success ? @"已检测到历史配置" : @"获取配置失败";
        NSString *message = success ? [[NSString alloc] initWithFormat:@"所配置SSID：%@，\n密码：%@，\n 连接状态：%@", result[@"ssid"],  result[@"password"], result[@"state"] ? @"已连接" : @"未连接"] : @"请重试或重新进行配网操作";
        NSString *okActionTitle = success ? @"跳过配网" : @"确定";
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message: message preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *ok = [UIAlertAction actionWithTitle:okActionTitle style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            if (success) {
                WTEMSInfoController *controller = [[WTEMSInfoController alloc] init];
                [self.navigationController pushViewController:controller animated:YES];
            }
        }];
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"继续配网" style:UIAlertActionStyleDefault handler:nil];
        if (success) {
            [alert addAction:cancel];
        }
        [alert addAction:ok];
        [self presentViewController:alert animated:YES completion:nil];
    }];
}

- (void)configurationWifiWith:(NSString *)ssid password:(NSString *)password {
    [[WTWifiCenter sharedInstance] wifiConfigurationWith:ssid password:password completionHandler:^(bool result, NSError * _Nullable error) {
        bool success = result && !error;
        NSString *title = success ? @"恭喜配网成功!" : @"配网失败，请重试";
        NSString *message = success ? nil : @"请确认密码是否正确或是否连接硬件热点";
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message: message preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *ok = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            if (success) {
                WTEMSInfoController *controller = [[WTEMSInfoController alloc] init];
                [self.navigationController pushViewController:controller animated:YES];
            }
        }];
        [alert addAction:ok];
        [self presentViewController:alert animated:YES completion:nil];
    }];
}


- (void) updateEMSConfigurationTap{
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
}

#pragma mark - lazy initila


- (UIButton *)button {
    if (_button == nil) {
        _button = [[UIButton alloc] initWithFrame:CGRectMake(100, 100, 200, 40)];
        [_button setTitle:@"查询WIFI列表" forState:UIControlStateNormal];
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
        _loadConfigBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 150, 200, 40)];
        [_loadConfigBtn setTitle:@"查询已配网信息" forState:UIControlStateNormal];
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
        _updateEMSBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 200, 200, 40)];
        [_updateEMSBtn setTitle:@"更新EMS参数配置" forState:UIControlStateNormal];
        [_updateEMSBtn setTitleColor:UIColor.grayColor forState:UIControlStateHighlighted];
        [[_updateEMSBtn layer] setBorderColor:UIColor.grayColor.CGColor];
        _updateEMSBtn.layer.cornerRadius = 5;
        _updateEMSBtn.layer.borderWidth = 0.5;
        [_updateEMSBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_updateEMSBtn addTarget:self action:@selector(updateEMSConfigurationTap) forControlEvents:UIControlEventTouchUpInside];
    }
    return _updateEMSBtn;
}

- (UITableView *)tableview {
    if (_tableview == nil) {
        _tableview = [[UITableView alloc] initWithFrame:CGRectMake(30, 250, UIScreen.mainScreen.bounds.size.width - 60, UIScreen.mainScreen.bounds.size.height - 300)];
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
    NSString *message = [[NSString alloc] initWithFormat:@"要进行配网，请先输入%@的密码", ssid];
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"配置网络" message: message preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        [textField setPlaceholder:@"请输入WIFI密码"];
    }];
    
    UIAlertAction *ok = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *pwd = alert.textFields.firstObject.text;
        if (pwd.length > 0) {
            [self configurationWifiWith:ssid password:pwd];
        }
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleDefault handler:nil];
    
    [alert addAction:cancel];
    [alert addAction:ok];
    [self presentViewController:alert animated:YES completion:nil];
    

}

#pragma mark - WTWifiCenterDelegate


- (void)didConnectedWith:(NSString *)ssid {
    NSLog(@"已连接热点%@", ssid);
}

- (void)didDisconnectedWith:(NSString *)ssid {
    NSLog(@"----热点Ping不通%@", ssid);
    if (ssid) {
        NEHotspotConfiguration *hotspotConfig = [[NEHotspotConfiguration alloc] initWithSSID:ssid passphrase:@"12345678" isWEP:NO];
        [[NEHotspotConfigurationManager sharedManager] applyConfiguration:hotspotConfig completionHandler:^(NSError * _Nullable error) {
            if (error && error.code != 13 && error.code != 7) {
                NSLog(@"加入失败");
            }else if(error.code ==7){
                NSLog(@"已取消");
            }else{
                NSLog(@"已连接");
            }
        }];
    }
    
}

- (void)didUpdateEMSParametersSuccess {
    NSLog(@"已成功更新EMS参数配置");
}

@end
