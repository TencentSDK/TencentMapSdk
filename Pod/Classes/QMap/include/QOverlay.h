/*
 ============================================================================
 Name           : QOverlay.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QOverlay declaration
 ============================================================================
 */

#ifndef SOSOMapAPI_QOverlay_h
#define SOSOMapAPI_QOverlay_h
#import "QAnnotation.h"
#import "QGeometry.h"

/**
 *QOverlay:地图覆盖物的基类，所有地图的覆盖物需要继承自此类
 *Author:ksnowlv
 **/
@protocol QOverlay <QAnnotation>
@required

/**返回区域中心坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

/**返回区域外接矩形**/
@property(nonatomic, readonly) QMapRect boundingMapRect;

@end

#endif
