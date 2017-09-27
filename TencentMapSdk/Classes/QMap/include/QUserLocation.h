/*
 ============================================================================
 Name           : QUserLocation.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QUserLocation declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import "QAnnotation.h"

/**
 *QUserLocation:定位信息类
 *Author:ksnowlv
 **/
@interface QUserLocation : NSObject <QAnnotation>

/**位置更新状态，如果正在更新位置信息，则该值为YES**/
@property(readonly, nonatomic, getter=isUpdating) BOOL updating;

/**位置信息，如果QMapView的showsUserLocation为NO，或者尚未定位成功，则该值为0**/
@property( nonatomic, readonly) CLLocationCoordinate2D location;

/**定位标注点要显示的标题信息**/
@property(nonatomic, readonly) NSString *title;

/**定位标注点要显示的副标题信息.**/
@property(nonatomic, readonly) NSString *subtitle;
@property(readonly, nonatomic) CLLocationSpeed speed;//速度
@property(readonly, nonatomic) CLLocationDirection course;//方向角
@property(readonly, nonatomic) CLLocationAccuracy horizontalAccuracy;//水平精度
/**
 * 吸附后的坐标，如果没有导航，则跟原始坐标一致
 */
@property(readonly, nonatomic) CLLocationCoordinate2D adjustLocation;
/**
 * 吸附后的角度，如果没有导航，则跟原始角度一致
 */
@property(nonatomic, readonly) CLLocationDirection adjustCourse;

@property(nonatomic, strong)UIView *customCalloutView;
@end
