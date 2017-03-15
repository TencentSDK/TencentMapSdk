//
//  QPolygonUtil.h
//  QMapKit
//
//  Created by duanli on 16/5/20.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QGeometry.h"
#import <CoreLocation/CoreLocation.h>


@interface QPolygonUtil : NSObject

/*!
 *  @brief  获取当前多边形里最优的展示区域
 *
 *  @param  point 绘制多边形的点串
 *  @param  count 点串数量
 *
 *  @return 返回一个最优展示的经纬度范围区域
 *
 *  @since
 */
+ (QCoordinateRegion)getMaxRectInPolygon:(CLLocationCoordinate2D*)point
                                   count:(int)count;

/*!
 *  @brief  获取某个区域内可展示的最大字体,如果算出的字体小于kMinSizeOfPolygonText定义的字体，则返回0 
 *
 *  @param string   需要展示的文本
 *  @param rect     需要展示的区域
 *  @param fontName 需要展示的字体名称
 *  @param [out] size 可展示最大字体的文本大小
 *  @param maxFontSize 最大的字体
 *  @param minFontSize 最小的字体
 *  @return 区域内可展示的最大字体
 *
 *  @since 
 */
+ (CGFloat)maxFontSizeThatFitsForString:(NSString*)string
                                 inRect:(CGRect)rect
                               withFont:(NSString*)fontName
                                   size:(CGSize*)size
                            maxFontSize:(CGFloat)maxFontSize
                            minFontSize:(CGFloat)minFontSize;

@end
