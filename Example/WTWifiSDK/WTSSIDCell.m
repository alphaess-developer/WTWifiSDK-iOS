//
//  WTSSIDCell.m
//  WTWifiSDK_Example
//
//  Created by cavan on 2022/8/17.
//  Copyright © 2022 Cavan. All rights reserved.
//

#import "WTSSIDCell.h"

@interface WTSSIDCell()

@end

@implementation WTSSIDCell

+ (instancetype)cellWithTableView:(UITableView *)tableView {
    static NSString *ID = @"SSIDCellID";
    WTSSIDCell *cell = [tableView dequeueReusableCellWithIdentifier:ID];
    if (!cell) {
        cell = [[WTSSIDCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:ID];
    }
    return cell;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        [self initWithView];
    }
    return self;
}

- (void)initWithView {
    
}

- (void)layoutSubviews {
    [super layoutSubviews];

}

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

}

@end
