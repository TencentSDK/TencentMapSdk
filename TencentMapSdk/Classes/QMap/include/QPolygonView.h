/*
 ============================================================================
 Name           : QPolygonView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPolygonView declaration
 ============================================================================
 */

#import "QOverlayPathView.h"
#import "QPolygon.h"

/**
 *QPolygonView:定义一个多边形View
 *Author:ksnowlv
 **/
@interface QPolygonView : QOverlayPathView

/**
 *根据指定的多边形生成一个多边形View
 *@param polygon 指定的多边形数据对象
 *@return 新生成的多边形View
 */
- (id)initWithPolygon:(QPolygon *)polygon;

/**View对应的多边形数据**/
@property(nonatomic, readonly) QPolygon *polygon;

@end
