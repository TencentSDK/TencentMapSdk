/*
 ============================================================================
 Name           : QCircleView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QCircleView declaration
 ============================================================================
 */

#import "QOverlayPathView.h"
#import "QCircle.h"

/**
 *QCircleView:定义圆对应的View
 *Author:ksnowlv
 **/
@interface QCircleView : QOverlayPathView

/**
 *根据指定圆生成对应的View
 *@param circle 指定的圆
 *@return 生成的View
 */
- (id)initWithCircle:(QCircle *)circle;

/**View对应的圆**/
@property(nonatomic, readonly) QCircle *circle;

@end
