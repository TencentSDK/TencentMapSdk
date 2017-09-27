//
//  SimpleNavigation.h
//  QMapKit
//
//  Created by NancyNan on 10/4/17.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "QMRoute.h"
#import "RouteResult.h"
#import "QRouteSearch.h"

typedef NS_ENUM(NSUInteger, SimpleNavigationType) {
    SimpleNavigationTypeWalk,
    SimpleNavigationTypeRide,
};

@protocol SimpleNavigationDelegate;

@interface SimpleNavigation : NSObject

@property (nonatomic, weak) id <SimpleNavigationDelegate> delegate;
@property (nonatomic, assign, readonly) SimpleNavigationType naviType;
@property (nonatomic, assign, readonly) BOOL isNavigating;

/**
 SimpleNavigation实例化方法
 @param naviType 导航类型，步行或骑行
 */
- (instancetype)initWithNaviType:(SimpleNavigationType)naviType;

/**
 开始导航
 @param routeResult 导航的路线
 @return 返回值，YES:开启成功  NO:开启失败
 */
- (BOOL)startNavi:(RouteResult *)routeResult;

/**
 结束导航
 */
- (void)stopNavi;

/**
 将当前位置传入引擎
 @return 是否成功,非导航情况下返回NO
 */
- (BOOL)updateLocation:(CLLocation *)location;

@end

@protocol SimpleNavigationDelegate <NSObject>

/**
 调用updateLocation后，引擎回调此方法，返回吸附后的location和点索引，走过的路置灰时需要用到这两个值
 @param simpleNavigation 轻量导航实例
 @param matchedLocation 吸附后的location，当吸附失败时，matchedLocation为updateLocation方法传入的location
 @param pointIndex 当前定位点吸附到路线上的点串索引，-1表示吸附失败
 */
- (void)simpleNavigation:(SimpleNavigation *)simpleNavigation didUpdateMatchedLocation:(CLLocation *)matchedLocation pointIndex:(int)pointIndex;

/**
 返回实时的导航信息,当吸附失败时，route无效
 @param simpleNavigation 轻量导航实例
 @param route 剩余时间、剩余距离等信息
 */
- (void)simpleNavigation:(SimpleNavigation *)simpleNavigation didUpdateRoute:(QMRoute *)route;

/**
 偏航回调
 @param simpleNavigation 轻量导航实例
 */
- (void)didOnWayout:(SimpleNavigation *)simpleNavigation;

/**
 到达目的地回调
 @param simpleNavigation 轻量导航实例
 */
- (void)didArriveDestination:(SimpleNavigation *)simpleNavigation;

/**
 * 偏航重算开始
 @param simpleNavigation 轻量导航实例
 */
- (void)routeRecalculateDidStart:(SimpleNavigation *)simpleNavigation;

/**
 * 偏航重算开始
 @param simpleNavigation 轻量导航实例
 @param routeResult 路线结果
 */
- (void)simpleNavigation:(SimpleNavigation *)simpleNavigation routeRecalculateDidFinish:(RouteResult *)routeResult;

/**
 * 偏航重算开始
 @param simpleNavigation 轻量导航实例
 @param error 路线失败
 */
- (void)simpleNavigation:(SimpleNavigation *)simpleNavigation routeRecalculateDidFailWithError:(QRouteSearchError *)error;

@end
