//
//  QUserLocationView.h
//  QMapKitLite
//
//  Created by ZhangChao on 2017/3/22.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QUserLocation.h"
#import "QAnnotationView.h"
@interface QUserLocationView :QAnnotationView

/**
 * 关联的annotation,readonly
 */
@property (nonatomic, readonly) QUserLocation* userLocation;

/**
 * 非导航下用户位置图标路径。
 * 用法: 获取图标的绝对路径后,请调用QMapView的
 * - (NSString*)getImageFilePathFlag:(NSString*)imageFilePath 方法
 * 然后再将返回值赋值给pathForLocationImage
 * 下同
 */
@property(nonatomic,strong)NSString* pathForLocationImage;

/**
 * 导航下用户位置图标路径
 */
@property(nonatomic,strong)NSString* pathForNaviLocationImage;

/**
 * 定位失败后用户位置图标路径
 */
@property(nonatomic,strong)NSString* pathForFailurelocationImage;

/**
 * 非导航下用户位置图标
 */
@property(nonatomic,strong)UIImage* locationImage;

/**
 * 导航下用户位置图标
 */
@property(nonatomic,strong)UIImage* naviLocationImage;

/**
 * 定位失败后用户位置图标
 */
@property(nonatomic,strong)UIImage* failurelocationImage;

/**
 * 定位精度圈颜色
 */
@property(nonatomic,strong)UIColor* circleColor;

/**
 * 重置位置图片到默认，包括非导航下、导航和定位失败的图标
 */
-(void) resetLocationImages;

/**
 * 重置光圈颜色
 */
-(void) resetCircleColor;
@end
