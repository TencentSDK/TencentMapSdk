//
//  RouteTrafficInfo.h
//  QMapKit
//
//  Created by NancyNan on 29/11/2016.
//  Copyright © 2016 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, RouteTrafficEventType)
{
    RouteTrafficEventTypeSlow = 0,//缓行
    RouteTrafficEventTypeJam = 1,//堵车
    RouteTrafficEventTypeOther = 11,//其他
    RouteTrafficEventTypeUnCrowded = 12,//道路畅通
    RouteTrafficEventType_JAM2 = 201,     //猪肝红
    RouteTrafficEventTypeMaxType//
};

@interface RouteTrafficInfo : NSObject

@property (nonatomic, assign) int startIndex;//路况的起点索引
@property (nonatomic, assign) int endIndex;//路况的终点索引
@property (nonatomic, assign) int color;//颜色
@property (nonatomic, assign) int speed;//速度
@property (nonatomic, assign) int eventType;//事件类型
@property (nonatomic, assign) CLLocationCoordinate2D startCoordinate;//路况起点坐标
@property (nonatomic, assign) CLLocationCoordinate2D endCoordinate;//路况终点坐标
@property (nonatomic, assign) int shapeType;//形状
@end
