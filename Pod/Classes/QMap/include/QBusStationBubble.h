//
//  QBusStationBubble.h
//  QMapKit
//
//  Created by BruceAi on 16/5/6.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QAnnotation.h"

/*
 * 设置气泡的第一种方式:车站名 + 上车/下车/进站/出站 + 线路名
 * 用户可自定义相应文本的字体，文本的颜色
 * 设置气泡的第二种方式:上层完全自定义一个UIView
 */
@interface QBusStationBubble : NSObject<QAnnotation>
{
    @package
    CLLocationCoordinate2D _coordinate;
}

/*公交气泡站点名*/
@property (nonatomic,strong) NSString* stationName;
/*公交气泡站点字体*/
@property (nonatomic,strong) UIFont* stationFont;
/*公交气泡站点文字颜色*/
@property (nonatomic,strong) UIColor* stationTextColor;
/*动作(上车/下车/进站/出站)*/
@property (nonatomic,strong) NSString* action;
/*动作字体*/
@property (nonatomic,strong) UIFont* actionFont;
/*动作文本颜色*/
@property (nonatomic,strong) UIColor* actionTextColor;
/*线路名*/
@property (nonatomic,strong) NSString* lineName;
/*线路文本字体*/
@property (nonatomic,strong) UIFont* lineFont;
/*线路文本颜色*/
@property (nonatomic,strong) UIColor* lineTextColor;
/*自定义视图*/
@property (nonatomic,strong) UIView* customView;
/*文本模式 默认文本模式{station} {action}\n{line}*/
@property (nonatomic,strong) NSString* pattern;
/*地理位置*/
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end
