/*
 ============================================================================
 Name           : QPinAnnotationView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPinAnnotationView declaration
 ============================================================================
 */

#import "QAnnotationView.h"


@class QPinAnnotationView;

/**
 *QPinAnnotationColor:大头针颜色
 *Author:ksnowlv
 **/
enum {
    QPinAnnotationColorRed = 0,/**红色大头针**/
    QPinAnnotationColorGreen,/**绿色大头针**/
    QPinAnnotationColorYellow/**黄色大头针**/
} ;

typedef NSUInteger QPinAnnotationColor;

/**
 *QPinAnnotationView:定义类似大头针效果的annotation view
 *Author:ksnowlv
 **/
@interface QPinAnnotationView : QAnnotationView

/**
 * 大头针的颜色，有QPinAnnotationColorRed, QPinAnnotationColorGreen, QPinAnnotationColorYellow三种
 **/
@property(nonatomic) QPinAnnotationColor pinColor;

/**下落动画效果**/

- (void)animatesDrop:(id)object;
@end
