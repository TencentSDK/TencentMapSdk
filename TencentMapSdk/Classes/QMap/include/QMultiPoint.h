/*
 ============================================================================
 Name           : QMultiPoint.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QMultiPoint declaration
 ============================================================================
 */

#import "QShape.h"
#import "QGeometry.h"

/**
 *QMultiPoint:定义多个坐标点
 *Author:ksnowlv
 **/
@interface QMultiPoint : QShape{
@package
    QMapPoint *_points;
    NSUInteger _pointCount;
    QMapRect _boundingRect;
}

/**坐标点数组**/
@property(nonatomic, readonly) QMapPoint *points;

/**坐标点的个数**/
@property(nonatomic, readonly) NSUInteger pointCount;

/**
 *将经纬度坐标数据转换为直角坐标点数据，并拷贝到指定的数组中
 *@param coords 经纬度坐标数组，转换后的坐标将存储到该数组中，该数组长度必须大于等于要拷贝的坐标点的个数（range.length）
 *@param range 指定要拷贝的数据段 
 */
- (void)getCoordinates:(CLLocationCoordinate2D *)coords range:(NSRange)range;

@end
