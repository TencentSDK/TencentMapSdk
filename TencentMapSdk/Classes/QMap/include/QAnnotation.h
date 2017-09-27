/*
 ============================================================================
 Name           : QAnnotation.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QAnnotation declaration
 ============================================================================
 */

#ifndef SOSOMapAPI_QAnnotation_h
#define SOSOMapAPI_QAnnotation_h

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
/**
 * QAnnotation:该类为标注点的protocol，提供了标注类的基本信息函数
 */
@protocol QAnnotation <NSObject>

/**
 * 获取annotation中心点对应的经纬度坐标
 * @return 返回annotation中心点对应的经纬度坐标
 */
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

@property(nonatomic,assign)BOOL autoAdjustCalloutViewPositon;

@optional

/**
 *获取annotation标题
 *@return 返回annotation的标题信息
 */
- (NSString *)title;

/**
 *获取annotation标题
 *@return 返回annotation的副标题信息
 */
- (NSString *)subtitle;

/**自定义UIView**/
@property(nonatomic, strong)UIView *customCalloutView;

@end

#endif
