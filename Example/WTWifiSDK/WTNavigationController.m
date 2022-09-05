//
//  WTNavigationController.m
//  WTWifiSDK_Example
//
//  Created by cavan on 2022/8/25.
//  Copyright © 2022 Cavan. All rights reserved.
//

#import "WTNavigationController.h"

@interface WTNavigationController ()

@end

@implementation WTNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (UIViewController *)childViewControllerForStatusBarStyle {
    return self.topViewController;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
