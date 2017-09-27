//
//  RouteResult.h
//  QQMap
//
//  Created by Nopwang on 5/6/11.
//  Copyright 2011 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QGeometry.h"
#import "QRouteInfo.h"

@class QPlaceInfo;
@class QYZXRouteReq;
typedef struct _GuidanceMapPoint
{
    int x;
    int y;
}GuidanceMapPoint;
@interface RouteResult : NSObject {

    NSArray *routes_;
    // added by nancynan 2012-6-14 for taxi fees
    NSArray *taxiFees_;
    NSString *taxiFeeString_;
    
    NSInteger selectedRouteIndex_;
    BOOL isFromAndToIdentical_;
}

@property (nonatomic) int forkIndex;
@property (nonatomic) double forkX;
@property (nonatomic) double forkY;
@property (nonatomic) int saveTime;
@property (nonatomic, strong) NSString *dynReason;

@property (nonatomic, strong) NSArray *routes;
@property (nonatomic, strong) NSArray *taxiFees;
@property (nonatomic, strong) NSString *taxiFeeString;
@property (nonatomic) NSInteger selectedRouteIndex;
@property (nonatomic) BOOL isFromAndToIdentical;

@property (nonatomic) BOOL isLocalResult;
@property (nonatomic, strong) NSString *reqRouteUrl;//保存在线路线请求返回的url

@property (nonatomic, assign) BOOL isBoundsResult;
@property (nonatomic, assign) GuidanceMapPoint *fencePoints;
@property (nonatomic, assign) GuidanceMapPoint *mapPoints;
@property (nonatomic, assign) int fencePointsCount;

@property(nonatomic, strong) id context;

@property(nonatomic, strong) NSArray *routeGeos;
@property(nonatomic, assign) int curDstRouteGeoIndex;
@property(nonatomic, strong) QYZXRouteReq *routeReq;

/**是否显示导航路线的起点和终点图标**/
@property(nonatomic,assign)BOOL bHidePoints;
@property(nonatomic,assign)BOOL bHideArrow;

//动态换路信息
@property(nonatomic, assign) int valid_time; //小于30s大于0，默认为错误；-1表示不再请求
@property(nonatomic, assign) int route_type; //0:正常算路 1:动态换路结果
@property(nonatomic, strong) NSString *previous_routeid; //上次动态换路的routeid


- (void)parseCoorPoints:(NSString *)coors;
- (void)parseCarCoorPoints:(NSString *)coors;

- (BOOL)isTypeBusByRow:(int)row;
- (BOOL)isTypeCarByRow:(int)row;
- (BOOL)isTypeWalkByRow:(int)row;
- (BOOL)isTypeBus;
- (BOOL)isTypeCar;
- (BOOL)isTypeWalk;
- (BOOL)isHassub;
- (BOOL)hasRoutes;
- (id)selectedRoute;
- (id)typeRoute;
/**返回选中路线的起始点信息，只包括经纬度信息，name和address字段暂时为空，默认selectedRouteIndex==0**/
- (QPlaceInfo*)startPlaceInfo;
/**返回选中路线的结束点信息，只包括经纬度信息，name和address字段暂时为空，默认selectedRouteIndex==0**/
- (QPlaceInfo*)endPlaceInfo;
/**返回选中路线的途经点信息，只包括经纬度，name信息，address字段暂时为空，默认selectedRouteIndex==0**/
- (NSArray*)passesPlaceInfo;
/**返回被选择的Route的外接Rect,默认selectedRouteIndex==0**/
-(QMapRect)rectForSelectedRoute;

/**返回选中路线的routeid，默认selectedRouteIndex==0**/
- (NSString *)routeId;
/**返回选中路线的args，默认selectedRouteIndex==0**/
- (NSString *)args;

- (int)getRoutesCount;

/**
 *  个性化路线推荐理由
 *
 *  @param index 路线索引
 *
 *  @return 个性化路线推荐理由
 */
- (NSString*)getRecommendReason:(int)index;

/**
 *  个性化路线推荐类型
 *
 *  @param index 路线索引
 *
 *  @return 个性化路线推荐类型
 */
- (NSString*)getRecommendType:(int)index;


/**
 *  选中路线的routeID
 *
 *  @return 选中路线的routeID
 */
- (NSString*)selectedRouteId;

/**
 *  选中路线点串
 *  点串格式为差分的墨卡托坐标，以分号相隔
 *
 *  @return 选中路线的路线点串
 */
- (NSString*)selectedRouteGeoPoints;

/**
 *  选中路线点串数组
 *  点串为经纬度坐标
 *
 *  @return 选中路线的路线点串
 */
- (NSArray <QRoutePoint *> *)selectedRoutePointsArray;

/**
 * 返回range里的点串对应的路况信息
 */
- (NSArray <QRouteLine *> *)routeLineArrayFromPointRange:(NSRange)range;

@end
