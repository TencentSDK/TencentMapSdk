/*
 ============================================================================
 Name           : QOverlayView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QOverlayView declaration
 ============================================================================
 */

#import <UIKit/UIKit.h>
#import "QGeometry.h"
#import "QOverlay.h"

/**
 *QOverlayView：地图覆盖物View的基类，所有地图覆盖物View需要继承自此类
 *Author:ksnowlv
 **/
@interface QOverlayView : UIView
{
@package
    QMapRect _boundingMapRect;
    CGAffineTransform _mapTransform;
}

/**
 *初始化并返回一个overlay view
 *@param overlay 关联的overlay对象
 *@return 初始化成功则返回overlay view,否则返回nil
 */
- (id)initWithOverlay:(id <QOverlay>)overlay;

/**关联的overlay对象**/
@property(nonatomic, readonly) id <QOverlay> overlay;


@end

