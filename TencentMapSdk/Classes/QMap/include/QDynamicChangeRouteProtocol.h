//
//  QDynamicChangeRouteProtocol.h
//  SOSOMap
//
//  Created by weizhengli on 2016.10.21.
//  Copyright 2016 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "RouteResult.h"

@protocol QDynamicChangeRouteProtocol <NSObject>

@required


/**
 是否可以动态换路，在偏航和更换目的地时不进行动态换路

 @return 是否可以动态换路
 */
- (BOOL)canDynamicChangeRoute;

/**
 请求地址

 @return 动态换路的服务器地址
 */
- (NSString*)httpString;


/**
 构造请求

 @param coord        匹配坐标
 @param segmentIndex 匹配索引

 @return 请求数据
 */
- (NSData*)httpDataPost:(CLLocationCoordinate2D)coord MatchedIndex:(int)segmentIndex;


/**
 动态换路数据解析与处理

 @param data        [in]网络返回的数据
 @param routeResult [out]解析出的路线
 @param validTime   [out]下次请求时间

 @return  0 数据解包成功（可能换路成功，可能只是更改下次事件）. -1 表示解包失败， -2 其他返回值
 */
- (int)handleDynamicChangeRouteData:(NSData*)data RouteResult:(RouteResult**)routeResult andNextTime:(int *)validTime;


@end
