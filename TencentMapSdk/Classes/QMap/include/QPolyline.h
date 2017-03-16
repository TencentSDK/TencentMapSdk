/*
 ============================================================================
 Name           : QPolyline.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPolyline declaration
 ============================================================================
 */

#import "QMultiPoint.h"
#import "QOverlay.h"

/**
 *QPolyline:定义一段折线
 *Author:ksnowlv
 **/
@interface QPolyline : QMultiPoint <QOverlay>

/**
 *根据指定坐标点生成一段折线
 *@param points 指定的直角坐标点数组
 *@param count 坐标点的个数
 *@return 新生成的折线对象
 */
+ (QPolyline *)polylineWithPoints:(QMapPoint *)points count:(NSUInteger)count;

/**
 *根据指定坐标点生成一段折线
 *@param coords 指定的经纬度坐标点数组
 *@param count 坐标点的个数
 *@return 新生成的折线对象
 */
+ (QPolyline *)polylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;


@end
