/*
 ============================================================================
 Name           : QCircle.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QCircle declaration
 ============================================================================
 */

#import "QShape.h"
#import "QOverlay.h"

/**
 *QCircle:定义一个圆
 *Author:ksnowlv
 **/
@interface QCircle : QShape <QOverlay>{

@package
    CLLocationCoordinate2D _coordinate;
    double _radius;
    QMapRect _boundingMapRect;
}

/**
 *根据中心点和半径生成圆
 *@param coord 中心点的经纬度坐标
 *@param radius 半径，单位：米
 *@return 新生成的圆
 */
+ (QCircle *)circleWithCenterCoordinate:(CLLocationCoordinate2D)coord
                                  radius:(double)radius;

/**
 *根据指定的直角坐标矩形生成圆，半径由较长的那条边决定，radius = MAX(width, height)/2
 *@param mapRect 指定的直角坐标矩形
 *@return 新生成的圆
 */
+ (QCircle *)circleWithMapRect:(QMapRect)mapRect;

/**
 *中心点坐标
 ****/
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/***半径，单位：米****/
@property (nonatomic, readonly) double radius;

/**该圆的外接矩形**/
@property (nonatomic, readonly) QMapRect boundingMapRect; 

@end
