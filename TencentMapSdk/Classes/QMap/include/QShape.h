/*
 ============================================================================
 Name           : QShape.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QShape declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import "QAnnotation.h"

/**
 *QShape:定义了基于QAnnotation的QShape类的基本属性和行为，不能直接使用，必须子类化之后才能使用
 *Author:ksnowlv
 **/
@interface QShape : NSObject <QAnnotation>{
@package
    NSString *_title;
    NSString *_subtitle;
    UIView *_customCalloutView;
}
/**标题**/
@property(nonatomic, copy) NSString *title;

/**副标题**/
@property(nonatomic, copy) NSString *subtitle;

@property(nonatomic, assign) BOOL animationDidStop;

/**设置是否自动调整calloutView气泡位置**/
@property(nonatomic,assign)BOOL autoAdjustCalloutViewPositon;


@end
