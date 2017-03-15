/*
 ============================================================================
 Name           : QOverlayPathView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QOverlayPathView declaration
 ============================================================================
 */

#import "QOverlayView.h"

/**
 *QOverlayPathView：定义了OverlayView，并且在MapKit中定制了几个经常使用的OverlayView
 *Author:ksnowlv
 **/
@interface QOverlayPathView : QOverlayView{
@package
    UIColor *_fillColor;
    UIColor *_strokeColor;
    CGFloat _lineWidth;
}

/**填充颜色**/
@property(nonatomic, strong) UIColor *fillColor;
/**画笔颜色,只取RGB值，丢到Alpha值**/
@property(nonatomic, strong) UIColor *strokeColor;

/**画笔宽度，默认为0**/
@property(nonatomic, assign) CGFloat lineWidth; 


@end
