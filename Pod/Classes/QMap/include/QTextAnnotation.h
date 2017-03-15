//
//  QTextAnnotation.h
//  QMapKit
//
//  Created by duanli on 16/5/16.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QAnnotation.h"
#import "QGeometry.h"

@interface QTextAnnotation : NSObject<QAnnotation>

/*!
 *  @brief  中心点坐标
 *
 *  @since
 */
@property(nonatomic,assign)CLLocationCoordinate2D coordinate;

/*!
 *  @brief  文字绘制的rect
 *
 *  @since
 */
@property(nonatomic,assign)CGRect textRc;

/*!
 *  @brief  绘制的文本
 *
 *  @since
 */
@property(nonatomic,copy)NSString* text;

/*!
 *  @brief  绘制的字体名称,如果不设置，则默认为系统默认字体
 *
 *  @since
 */
@property(nonatomic,copy)NSString* fontName;

/*!
 *  @brief  文字绘制的字体大小
 *
 *  @since
 */
@property(nonatomic,assign)CGFloat fontSize;

/*!
 *  @brief  文字绘制的颜色,格式例如@"0x0079FF"，如果不设置，则默认为白色
 *
 *  @since
 */
@property(nonatomic,copy)NSString* textColorString;

/*!
 *  @brief  显示的最优区域
 *
 *  @since
 */
@property(nonatomic,assign)QCoordinateRegion showRegion;



/*!
 *  @brief  拼接AnnotationView需要展示的imageName
 *
 *  @return
 *
 *  @since
 */
@property(nonatomic,copy,readonly)NSString* imageName;

/*!
 *  @brief  是否需要自适应调整文本
 *
 *  @since
 */
@property(nonatomic,assign)BOOL autoAdjustTextPositon;


/*!
 *  @brief  设置最大的字体值 默认为60
 *
 *  @since
 */
@property(nonatomic,assign)CGFloat maxFontSize;


/*!
 *  @brief  设置最小的字体值 默认为1
 *
 *  @since
 */
@property(nonatomic,assign)CGFloat minFontSize;

@end
