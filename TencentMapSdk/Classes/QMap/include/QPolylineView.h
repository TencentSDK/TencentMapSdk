/*
 ============================================================================
 Name           : QPolylineView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPolylineView declaration
 ============================================================================
 */

#import "QOverlayPathView.h"
#import "QPolyline.h"

/**
 *QPolylineView:定义一个折线View
 *Author:ksnowlv
 **/
@interface QPolylineView : QOverlayPathView

/**
 *根据指定的折线生成一个折线View
 *@param polyline 指定的折线数据对象
 *@return 新生成的折线View
 */
- (id)initWithPolyline:(QPolyline *)polyline;

/**View对应的折线数据对象**/
@property (nonatomic, readonly) QPolyline *polyline;


@end
